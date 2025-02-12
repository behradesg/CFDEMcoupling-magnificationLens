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

    Copyright (C) 2023- Behrad Esgandri, JKU Linz, Austria


Class
    transferDataModel
    
Discription
    base class for transfer of data (e.g. face and cell ids) from OF to LIGGGHTS

SourceFiles
    transferDataModel.C
\*---------------------------------------------------------------------------*/

#ifndef transferDataModel_H
#define transferDataModel_H

#include "fvCFD.H"
#include "cfdemCloud.H"
#include "probeModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class transferDataModel Declaration
\*---------------------------------------------------------------------------*/

class transferDataModel
{

protected:

    // Protected data
        const dictionary& dict_;

        cfdemCloud& particleCloud_;

public:

    //- Runtime type information
    TypeName("transferDataModel");

    // Declare runtime constructor selection table

        declareRunTimeSelectionTable
        (
            autoPtr,
            transferDataModel,
            dictionary,
            (
                const dictionary& dict,
                cfdemCloud& sm
            ),
            (dict,sm)
        );


    // Constructors

        //- Construct from components
        transferDataModel
        (
            const dictionary& dict,
            cfdemCloud& sm
        );


    // Destructor

        virtual ~transferDataModel();


    // Selector

        static autoPtr<transferDataModel> New
        (
            const dictionary& dict,
            cfdemCloud& sm,
            word transferDataType
        );

    // Member Functions
        virtual void transferData() const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
