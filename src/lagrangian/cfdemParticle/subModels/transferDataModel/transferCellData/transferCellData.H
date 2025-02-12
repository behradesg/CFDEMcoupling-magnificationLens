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
    transfer boundary cells data e.g. Us, granular temperature and diagonal 
    components of stress tensor of magnification lens cellset to LIGGGHTS

SourceFiles
    transferCellData.C
\*---------------------------------------------------------------------------*/

#ifndef transferCellData_H
#define transferCellData_H

#include "transferDataModel.H"
#include "scalarIOList.H" //for  scalarList

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class transferCellData Declaration
\*---------------------------------------------------------------------------*/

class transferCellData
:
    public transferDataModel
{
private:

    const fvMesh& mesh_;
    
    dictionary propsDict_;
    
    wordList boundaryPatchNames_;
    
    const volVectorField& Us_;
    
    const volScalarField& Theta_;
    
    const volScalarField& Alpha_;
    
    // The diagonal components of the total stress tensor from TFM
    const volScalarField& PXX_; 
    
    const volScalarField& PYY_;
    
    const volScalarField& PZZ_;
        
    label sizeArray_;
    
    double** UsCell_;

    double** ThetaCell_;
    
    double** AlphaCell_;
    
    double** totPartVolCell_; // alpha [cell] * mesh.Volume [cell]
    
    double** PXXCell_;
    
    double** PYYCell_;
    
    double** PZZCell_;

    label calcTotNumCells(); //calculate the total # of boundary cells
    


public:

    //- Runtime type information
    TypeName("transferCellData");

    // Constructors

        //- Construct from components
        transferCellData
        (
            const dictionary& dict,
            cfdemCloud& sm
        );

    // Destructor

        ~transferCellData();


    // Member Functions
        void transferData() const;

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
