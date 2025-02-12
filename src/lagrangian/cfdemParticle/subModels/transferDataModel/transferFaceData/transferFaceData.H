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
    transfer patch face ids and fluxes to LIGGGHTS

SourceFiles
    transferFaceData.C
\*---------------------------------------------------------------------------*/

#ifndef transferFaceData_H
#define transferFaceData_H

#include "transferDataModel.H"
#include "scalarIOList.H" //for  scalarList
#include <string.h>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class transferFaceData Declaration
\*---------------------------------------------------------------------------*/

class transferFaceData
:
    public transferDataModel
{
private:

    const fvMesh& mesh_;
    
    dictionary propsDict_;

    wordList IDArrayNames_;
    
    wordList boundaryPatchNames_;
    
    const surfaceScalarField& massFlux;

    UPtrList<scalarIOList> patchFaceIDsPointerList_;

    labelList numPatchFaceIDsList_;
    
    label numboundaryPatchNames_;
        
    label sizeArray_;
    
    double** totPatchFaceIDs_;

    double** totPatchFaceFluxes_;

    label calcTotNumPatchFaces(); //calculate the total # of face ids of all patches
    
    void init();



public:

    //- Runtime type information
    TypeName("transferFaceData");

    // Constructors

        //- Construct from components
        transferFaceData
        (
            const dictionary& dict,
            cfdemCloud& sm
        );

    // Destructor

        ~transferFaceData();


    // Member Functions
        void transferData() const;

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
