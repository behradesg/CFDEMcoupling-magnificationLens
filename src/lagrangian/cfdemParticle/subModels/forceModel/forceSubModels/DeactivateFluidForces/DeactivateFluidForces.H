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
    Sets the fluid forces on the particles to zero in specified cellSets

Class
    DeactivateFluidForces

SourceFiles
    DeactivateFluidForces.C

\*---------------------------------------------------------------------------*/

#ifndef DeactivateFluidForces_H
#define DeactivateFluidForces_H

#include "forceSubModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class DeactivateFluidForces Declaration
\*---------------------------------------------------------------------------*/

class DeactivateFluidForces
:
    public forceSubModel
{
private:

    dictionary propsDict_;
    
    wordList insertionCellSetNames_;
    
    DynamicList<scalar> totalCellIDs;
    
    void init();

public:

    //- Runtime type information
    TypeName("DeactivateFluidForces");


    // Constructors

        //- Construct from components
        DeactivateFluidForces
        (
            const dictionary& dict,
            cfdemCloud& sm,
            forceModel& fm
        );

    // Destructor

        ~DeactivateFluidForces();


    // Member Functions

        void partToArray(label, vector&,const vector&, const vector& Ufluid=vector::zero, scalar Cd=scalar(0)) const;

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
