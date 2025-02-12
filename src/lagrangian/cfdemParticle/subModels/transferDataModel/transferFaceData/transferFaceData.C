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

Description
    transfer patch face fluxes and ids to LIGGGHTS

SourceFiles
    transferFaceData.C
\*---------------------------------------------------------------------------*/

#include "error.H"

#include "transferFaceData.H"
#include "addToRunTimeSelectionTable.H"
 

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(transferFaceData, 0);

addToRunTimeSelectionTable
(
    transferDataModel,
    transferFaceData,
    dictionary
);


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

// Construct from components
transferFaceData::transferFaceData
(
    const dictionary& dict,
    cfdemCloud& sm
)
:
    transferDataModel(dict,sm),
    mesh_(sm.mesh()),
    propsDict_(dict.subDict(typeName + "Props")),
    IDArrayNames_(propsDict_.lookup("magnificationLensPatchIDArrayNames")),
    boundaryPatchNames_(propsDict_.lookup("magnificationLensBoundaryPatchNames")),
    massFlux(mesh_.lookupObject<surfaceScalarField>("alphaRhoPhi.particles")),
    patchFaceIDsPointerList_(IDArrayNames_.size()),
    numPatchFaceIDsList_(IDArrayNames_.size()),
    numboundaryPatchNames_(boundaryPatchNames_.size()),
    sizeArray_(0),
    totPatchFaceIDs_(NULL),
    totPatchFaceFluxes_(NULL)
{
    init(); // initialization
    sizeArray_ = calcTotNumPatchFaces();
    // Allocation of memory for storing all patch face ids
    particleCloud_.dataExchangeM().allocateArray(totPatchFaceIDs_,0,1,sizeArray_);//array,initval,width,length
    // Allocation of memory for storing all patch face fluxes
    particleCloud_.dataExchangeM().allocateArray(totPatchFaceFluxes_,0,1,sizeArray_);//array,initval,width,length
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

transferFaceData::~transferFaceData()
{
     particleCloud_.dataExchangeM().destroy(totPatchFaceIDs_, sizeArray_);
     particleCloud_.dataExchangeM().destroy(totPatchFaceFluxes_, sizeArray_);
}

// * * * * * * * * * * * * * * * private Member Functions  * * * * * * * * * * * * * //
void transferFaceData::init() 
{
    for (int i=0; i<IDArrayNames_.size(); i++)
    {
        scalarIOList& patchFaceIDs_ = const_cast<scalarIOList&>(mesh_.lookupObjectRef<scalarIOList>(IDArrayNames_[i]));
        numPatchFaceIDsList_[i] = patchFaceIDs_.size();
        patchFaceIDsPointerList_.set(i, &patchFaceIDs_);

    }
}

// * * * * * * * * * * * * * * * public Member Functions  * * * * * * * * * * * * * //

void transferFaceData::transferData() const //add a function names transferData to the cfdemCloud
{
    // filling the face ids into their array 
    if(Pstream::master())
    {
            //creating one array and assigning the elements with the order of the defined patch names in couplingProperties!
            label counter_=0;
            for (int i=0; i<IDArrayNames_.size(); i++)
            {
                for (int j=0; j<numPatchFaceIDsList_[i]; j++)
                {
                    totPatchFaceIDs_[j + counter_][0] = patchFaceIDsPointerList_[i][j];
                }
                counter_ = counter_ + numPatchFaceIDsList_[i];
            }             
    }

    // filling the face fluxes into their array in the same order as face ids array
    List<scalarField> processorFluxes(Pstream::nProcs());
    label count_ = 0;
    for (int i=0; i<boundaryPatchNames_.size(); i++)
    {
        const label& patchID = mesh_.boundaryMesh().findPatchID(boundaryPatchNames_[i]);
        const scalarField& patchMassFlux = massFlux.boundaryField()[patchID];
        string boundaryNameStr(boundaryPatchNames_[i]);
        processorFluxes[Pstream::myProcNo()] = patchMassFlux;
        Pstream::gatherList(processorFluxes);

        if(Pstream::master())
        {
            for(int iProc=0; iProc<Pstream::nProcs(); iProc++)
            {
                 for(int j=0; j<processorFluxes[iProc].size(); j++)
                 {
                    totPatchFaceFluxes_[j+count_][0] = processorFluxes[iProc][j];
                                        
                 }
                 count_ = count_ + processorFluxes[iProc].size();
             }
         }
    }
    
    //sending face ids array to LIGGGHTS
    particleCloud_.dataExchangeM().giveData("totPatchFaceIDs","vector-global",totPatchFaceIDs_); //name should be same in the liggghts side, datatype, array
    Info << "give patch face ids done" << endl;
   
    //sending face fluxes array to LIGGGHTS
    particleCloud_.dataExchangeM().giveData("totPatchFaceFluxes","vector-global",totPatchFaceFluxes_); //name should be same in the liggghts side, datatype, array
    Info << "give patch face fluxes done" << endl;
    
}

// * * * * * * * calculate the size of the array for giveData to allocate the array! * * * * * * * //

label transferFaceData::calcTotNumPatchFaces()
{
    label totNumPatchFaces_ = 0;
    
    for (int i=0; i<IDArrayNames_.size() ; i++)
    {
         totNumPatchFaces_ = totNumPatchFaces_ + numPatchFaceIDsList_[i];
    }

    return totNumPatchFaces_;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
