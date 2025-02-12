/*---------------------------------------------------------------------------*\
License
    This is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This code is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.
    You should have received a copy of the GNU General Public License
    along with this code.  If not, see <http://www.gnu.org/licenses/>.

    Copyright (C) 2023- Behrad Esgandari, JKU Linz, Austria
\*---------------------------------------------------------------------------*/

#include "error.H"
#include "cellSet.H"
#include "DeactivateFluidForces.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(DeactivateFluidForces, 0);

addToRunTimeSelectionTable
(
    forceSubModel,
    DeactivateFluidForces,
    dictionary
);


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

// Construct from components
DeactivateFluidForces::DeactivateFluidForces
(
    const dictionary& dict,
    cfdemCloud& sm,
    forceModel& fm
)
:
    forceSubModel(dict,sm,fm),
    propsDict_(dict.subDict(typeName + "Props")),
    insertionCellSetNames_(propsDict_.lookup("insertionCellSetNames")),
    totalCellIDs(0)
{
    init();	
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

DeactivateFluidForces::~DeactivateFluidForces()
{
  totalCellIDs.clear();
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //
void DeactivateFluidForces::init() 
{       
   for (int i=0; i<insertionCellSetNames_.size(); i++)
   {
        cellSet CellIDs
        (
            IOobject
            (
		insertionCellSetNames_[i],
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

void DeactivateFluidForces::partToArray
(
    label index,
    vector& dragTot,
    const vector& dragEx,
    const vector& Ufluid,
    scalar Cd
) const
{
    label cellI = particleCloud_.particleCell(index);

    for (int i=0; i<totalCellIDs.size(); i++)
    {		     
         if (cellI == totalCellIDs[i])
         {          
	    dragTot = vector::zero;
	    Cd = 0.0;
	    break; 
         }                
    }  
    forceSubModel::partToArray(index,dragTot,dragEx,Ufluid,Cd);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
