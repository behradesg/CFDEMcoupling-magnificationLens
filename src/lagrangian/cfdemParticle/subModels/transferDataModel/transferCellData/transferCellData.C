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
    transfer cell data e.g. Us, Theta and normal stress values to LIGGGHTS

SourceFiles
    transferCellData.C
\*---------------------------------------------------------------------------*/

#include "error.H"

#include "transferCellData.H"
#include "addToRunTimeSelectionTable.H"
 

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(transferCellData, 0);

addToRunTimeSelectionTable
(
    transferDataModel,
    transferCellData,
    dictionary
);


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

// Construct from components
transferCellData::transferCellData
(
    const dictionary& dict,
    cfdemCloud& sm
)
:
    transferDataModel(dict,sm),
    mesh_(sm.mesh()),
    propsDict_(dict.subDict(typeName + "Props")),
    boundaryPatchNames_(propsDict_.lookup("magnificationLensBoundaryPatchNames")),
    Us_(mesh_.lookupObject<volVectorField>("U.particles")),
    Theta_(mesh_.lookupObject<volScalarField>("Theta.particles")),
    Alpha_(mesh_.lookupObject<volScalarField>("alpha.particles")),
    PXX_(mesh_.lookupObject<volScalarField>("P_XX.particles")),
    PYY_(mesh_.lookupObject<volScalarField>("P_YY.particles")),
    PZZ_(mesh_.lookupObject<volScalarField>("P_ZZ.particles")),
    sizeArray_(0),
    UsCell_(NULL),
    ThetaCell_(NULL),
    AlphaCell_(NULL),
    totPartVolCell_(NULL),
    PXXCell_(NULL),
    PYYCell_(NULL),
    PZZCell_(NULL)


{

    sizeArray_ = calcTotNumCells();
    // Allocation of memory for storing particle velocities (Us) per cell
    particleCloud_.dataExchangeM().allocateArray(UsCell_,0,3,sizeArray_);//array,initval,width,length
    // Allocation of memory for storing granular temperature (Theta) per cell
    particleCloud_.dataExchangeM().allocateArray(ThetaCell_,0,1,sizeArray_);//array,initval,width,length
    // Allocation of memory for storing solids volume fraction per cell
    particleCloud_.dataExchangeM().allocateArray(AlphaCell_,0,1,sizeArray_);//array,initval,width,length
    // Allocation of memory for storing total particle volume per cell
    particleCloud_.dataExchangeM().allocateArray(totPartVolCell_,0,1,sizeArray_);//array,initval,width,length
    // Allocation of memory for storing diagonal component of the total stress tensor per cell
    particleCloud_.dataExchangeM().allocateArray(PXXCell_,0,1,sizeArray_);//array,initval,width,length
    particleCloud_.dataExchangeM().allocateArray(PYYCell_,0,1,sizeArray_);//array,initval,width,length
    particleCloud_.dataExchangeM().allocateArray(PZZCell_,0,1,sizeArray_);//array,initval,width,length

}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

transferCellData::~transferCellData()
{
     particleCloud_.dataExchangeM().destroy(UsCell_, sizeArray_);
     particleCloud_.dataExchangeM().destroy(ThetaCell_, sizeArray_);
     particleCloud_.dataExchangeM().destroy(AlphaCell_, sizeArray_);
     particleCloud_.dataExchangeM().destroy(totPartVolCell_, sizeArray_);
     particleCloud_.dataExchangeM().destroy(PXXCell_, sizeArray_);
     particleCloud_.dataExchangeM().destroy(PYYCell_, sizeArray_);
     particleCloud_.dataExchangeM().destroy(PZZCell_, sizeArray_);
}

// * * * * * * * * * * * * * * * public Member Functions  * * * * * * * * * * * * * //

void transferCellData::transferData() const //add a function names transferData to the cfdemCloud
{
    // Defining the lists to keep the processor data
    List<List<vector>> processorUs(Pstream::nProcs());
    List<List<scalar>> processorTheta(Pstream::nProcs());
    List<List<scalar>> processorAlpha(Pstream::nProcs());
    List<List<scalar>> processortotPartVol(Pstream::nProcs());
    List<List<scalar>> processorPXX(Pstream::nProcs());
    List<List<scalar>> processorPYY(Pstream::nProcs());
    List<List<scalar>> processorPZZ(Pstream::nProcs());

    DynamicList<vector> UsList_;
    DynamicList<scalar> ThetaList_;
    DynamicList<scalar> AlphaList_;
    DynamicList<scalar> totPartVolList_;
    DynamicList<scalar> PXXList_;
    DynamicList<scalar> PYYList_;
    DynamicList<scalar> PZZList_;
    label countTheta_ = 0;
    label countAlpha_ = 0;
    label counttotPartVol_ = 0;
    label countUs_ = 0;
    label countStress_ = 0;
    // loop over the boundaries and gather the data form procs for each boundary
    for (int i=0; i<boundaryPatchNames_.size(); i++)
    {
        const polyPatch& patchType = mesh_.boundaryMesh()[boundaryPatchNames_[i]];
        const labelUList boundaryCells = patchType.faceCells();
        forAll(boundaryCells,i)
        {
            UsList_.append(Us_[boundaryCells[i]]);
            ThetaList_.append(Theta_[boundaryCells[i]]);
            AlphaList_.append(Alpha_[boundaryCells[i]]);
            totPartVolList_.append(Alpha_[boundaryCells[i]] * mesh_.V()[boundaryCells[i]]);
            PXXList_.append(PXX_[boundaryCells[i]]);
            PYYList_.append(PYY_[boundaryCells[i]]);
            PZZList_.append(PZZ_[boundaryCells[i]]);
        }
        // Storing data from each proc
        processorUs[Pstream::myProcNo()] = UsList_;
        processorTheta[Pstream::myProcNo()] = ThetaList_;
        processorAlpha[Pstream::myProcNo()] = AlphaList_;
        processortotPartVol[Pstream::myProcNo()] = totPartVolList_;
        processorPXX[Pstream::myProcNo()] = PXXList_;
        processorPYY[Pstream::myProcNo()] = PYYList_;
        processorPZZ[Pstream::myProcNo()] = PZZList_;
        // Gather data from procs
        Pstream::gatherList(processorUs);
        Pstream::gatherList(processorTheta);
        Pstream::gatherList(processorAlpha);
        Pstream::gatherList(processortotPartVol);
        Pstream::gatherList(processorPXX);
        Pstream::gatherList(processorPYY);
        Pstream::gatherList(processorPZZ);
        // clear the memory for dynamic lists
        UsList_.clear();
        ThetaList_.clear();
        AlphaList_.clear();
        totPartVolList_.clear();
        PXXList_.clear();
        PYYList_.clear();
        PZZList_.clear();

        // Fill the array to send to LIGGGHTS
        if(Pstream::master())
        {
            // granular temperature
            for(int iProc=0; iProc<Pstream::nProcs(); iProc++)
            {
                 for(int j=0; j<processorTheta[iProc].size(); j++)
                 {
                    ThetaCell_[j+countTheta_][0] = processorTheta[iProc][j];
                 }
                 countTheta_ = countTheta_ + processorTheta[iProc].size();
             }
             
            // solids volume fraction
            for(int iProc=0; iProc<Pstream::nProcs(); iProc++)
            {
                 for(int j=0; j<processorAlpha[iProc].size(); j++)
                 {
                    AlphaCell_[j+countAlpha_][0] = processorAlpha[iProc][j];
                 }
                 countAlpha_ = countAlpha_ + processorAlpha[iProc].size();
            }
               
            // total particle volume
            for(int iProc=0; iProc<Pstream::nProcs(); iProc++)
            {
                 for(int j=0; j<processortotPartVol[iProc].size(); j++)
                 {
                    totPartVolCell_[j+counttotPartVol_][0] = processortotPartVol[iProc][j];
                 }
                 counttotPartVol_ = counttotPartVol_ + processortotPartVol[iProc].size();
             }

            // Total stress diagonal components
            // size of the processorPXX, processorPYY and processorPZZ is the same.
            for(int iProc=0; iProc<Pstream::nProcs(); iProc++)
            {
                 for(int j=0; j<processorPXX[iProc].size(); j++)
                 {
                    PXXCell_[j+countStress_][0] = processorPXX[iProc][j];
                    PYYCell_[j+countStress_][0] = processorPYY[iProc][j];
                    PZZCell_[j+countStress_][0] = processorPZZ[iProc][j];
                 }
                 countStress_ = countStress_ + processorPXX[iProc].size();
             }    

            // particle velocities
            for(int iProc=0; iProc<Pstream::nProcs(); iProc++)
            {
                 for(int j=0; j<processorUs[iProc].size(); j++)
                 {
                     for(int i=0; i<processorUs[iProc][j].size(); i++)
                     {
                        UsCell_[j+countUs_][i] = processorUs[iProc][j][i];
                     }
                 }
                 countUs_ = countUs_ + processorUs[iProc].size();
             }
             
           } 
       
    }
    // just to be sure that the dynamic memory is cleaned.
    UsList_.clear();
    ThetaList_.clear();
    AlphaList_.clear();
    totPartVolList_.clear();
    PXXList_.clear();
    PYYList_.clear();
    PZZList_.clear();

    // sending particle velocities (Us) array to LIGGGHTS
    particleCloud_.dataExchangeM().giveData("UsCell","matrix-global",UsCell_); //name should be same in the liggghts side, datatype, array
    Info << "give particle velocities per cell done" << endl;
   
    // sending total stress diagonal components array to LIGGGHTS
    particleCloud_.dataExchangeM().giveData("PXXCell","vector-global",PXXCell_); //name should be same in the liggghts side, datatype, array
    Info << "give total stress tensor XX component per cell done" << endl;
    particleCloud_.dataExchangeM().giveData("PYYCell","vector-global",PYYCell_); //name should be same in the liggghts side, datatype, array
    Info << "give total stress tensor YY component per cell done" << endl;
    particleCloud_.dataExchangeM().giveData("PZZCell","vector-global",PZZCell_); //name should be same in the liggghts side, datatype, array
    Info << "give total stress tensor ZZ component per cell done" << endl;
   
    // sending granular temperature array to LIGGGHTS
    particleCloud_.dataExchangeM().giveData("ThetaCell","vector-global",ThetaCell_); //name should be same in the liggghts side, datatype, array
    Info << "give granular temperature per cell done" << endl;
    
    // sending solids volume fraction array to LIGGGHTS
    particleCloud_.dataExchangeM().giveData("AlphaCell","vector-global",AlphaCell_); //name should be same in the liggghts side, datatype, array
    Info << "give solids volume fraction per cell done" << endl;
    
    // sending total particle volume array to LIGGGHTS
    particleCloud_.dataExchangeM().giveData("totPartVolCell","vector-global",totPartVolCell_); //name should be same in the liggghts side, datatype, array
    Info << "give total particle volume per cell done" << endl;
   
}

// * * * * * * calculate the size of the array (cells) to allocate the array * * * * * * * * //
label transferCellData::calcTotNumCells()
{
    scalar totNumCells_ = 0;
    for (int i=0; i<boundaryPatchNames_.size() ; i++)
    {
         const polyPatch& patchID = mesh_.boundaryMesh()[boundaryPatchNames_[i]];
         const labelUList boundaryCells = patchID.faceCells();
         label numCells = boundaryCells.size();
         const scalar totNumLocalCells = returnReduce(numCells, sumOp<label>());         
         totNumCells_ = totNumCells_ + totNumLocalCells;
    }

    return totNumCells_;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
