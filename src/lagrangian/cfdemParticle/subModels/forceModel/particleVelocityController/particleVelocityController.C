/*---------------------------------------------------------------------------*\
    CFDEMcoupling - Open Source CFD-DEM coupling

    CFDEMcoupling is part of the CFDEMproject
    www.cfdem.com
                                Christoph Goniva, christoph.goniva@cfdem.com
                                Copyright 2009-2012 JKU Linz
                                Copyright 2012-     DCS Computing GmbH, Linz
-------------------------------------------------------------------------------
License
    This file is part of CFDEMcoupling.

    CFDEMcoupling is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 3 of the License, or (at your
    option) any later version.

    CFDEMcoupling is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with CFDEMcoupling; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Description
    This code is designed to realize coupled CFD-DEM simulations using LIGGGHTS
    and OpenFOAM(R). Note: this code is not part of OpenFOAM(R) (see DISCLAIMER).
\*---------------------------------------------------------------------------*/

#include "error.H"
#include "particleVelocityController.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(particleVelocityController, 0);

addToRunTimeSelectionTable
(
    forceModel,
    particleVelocityController,
    dictionary
);


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

// Construct from components
particleVelocityController::particleVelocityController
(
    const dictionary& dict,
    cfdemCloud& sm
)
:
    forceModel(dict,sm),
    propsDict_(dict.subDict(typeName + "Props")),
    UsTFM_(sm.mesh().lookupObject<volVectorField>("U.particles")),
    UsDEMField_(sm.mesh().lookupObject<volVectorField> ("Us")),
    rhoPart_(readScalar(propsDict_.lookup ("rhoPart"))),
    controllerCellSetNames_(propsDict_.lookup("controllerCellSetNames")),
    totalCellIDs(0),
    controllerErrorSwitch(propsDict_.lookup("controllerErrorSwitch")),
    controllVelocity(propsDict_.lookup("controllVelocity"))    
{
    // init force sub model
    setForceSubModels(propsDict_);
    init();
    // define switches which can be read from dict
    forceSubM(0).setSwitchesList(SW_TREAT_FORCE_EXPLICIT,true); // activate treatForceExplicit switch
    forceSubM(0).setSwitchesList(SW_TREAT_FORCE_DEM,true); // activate treatForceDEM switch
    forceSubM(0).setSwitchesList(SW_IMPL_FORCE_DEM,true); // activate implForceDEM switch
    forceSubM(0).setSwitchesList(SW_INTERPOLATION,true); // activate search for interpolate switch
    forceSubM(0).readSwitches();
}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

particleVelocityController::~particleVelocityController()
{
  totalCellIDs.clear(); 
}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //
void particleVelocityController::init() 
{
        
   for (int i=0; i<controllerCellSetNames_.size(); i++)
   {
        cellSet CellIDs
        (
            IOobject
            (
		controllerCellSetNames_[i],
		"constant/polyMesh/sets",
    		particleCloud_.mesh(),
    		IOobject::MUST_READ,
    		IOobject::NO_WRITE
            )
        );           
        const labelList& CellIDsList = CellIDs.toc();   
        for (int i=0; i < CellIDsList.size(); i++)
        {
            totalCellIDs.append(CellIDsList[i]);
        }
   }       
}

void particleVelocityController::setForce() const
{
    label cellI; 
    scalar Vs;
    vector position(0,0,0);
    vector UsDEM(0,0,0);
    vector UsTFM(0,0,0);
    interpolationCellPoint<vector> UsTFMInterpolator_(UsTFM_);
       
    #include "setupProbeModel.H"
	
    vector force;
    vector Ur_particle(0,0,0);
    scalar magUr_particle_sqr = 0;
    scalar numPart = 0;
        
    for(int index = 0; index < particleCloud_.numberOfParticles(); ++index)
    {
            force = vector::zero;
            cellI = particleCloud_.cellIDs()[index][0];
            
            if (cellI > -1) // particle Found
            {
                Vs = particleCloud_.particleVolume(index);
                position = particleCloud_.position(index);
                if ( forceSubM(0).interpolation() )
                 {
                	UsTFM = UsTFMInterpolator_.interpolate(position,cellI);
                 } else {
        
                       UsTFM = UsTFM_[cellI];
                 }
                     
            for (int i=0; i<totalCellIDs.size(); i++)
            {
		     
	         if (cellI == totalCellIDs[i])
	         { 	         
		     //imposing a force to derive individual particle velocity to the cell-averaged particle velocity in TFM
		     UsDEM = particleCloud_.velocity(index);
		     Ur_particle = UsTFM - UsDEM;
		     if (controllVelocity)
		     {		     	       		     	
		         force = Vs * rhoPart_ * (1.0/particleCloud_.mesh().time().deltaT().value()) * Ur_particle;		     				
	             }
		     
		     if (controllerErrorSwitch) 
		     {
		         Ur_particle = UsTFM - UsDEM;
		         magUr_particle_sqr += sqr(mag(Ur_particle));
		         numPart += 1;
		     }

                 }               
            }                    
           }                      
             // write particle based data to global array
             forceSubM(0).partToArray(index,force,vector::zero); 
    }
    	     if (controllerErrorSwitch) 
             {
                scalar totalControllerError = returnReduce(magUr_particle_sqr, sumOp<scalar>());
                scalar totNumPart = returnReduce(numPart, sumOp<scalar>());
                Info << "Controller error per particle is: " << sqrt(totalControllerError/max(totNumPart, SMALL)) << endl;
             }

}



// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
