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

    Copyright (C) 2015- Thomas Lichtenegger, JKU Linz, Austria

\*---------------------------------------------------------------------------*/

#include "error.H"

#include "transferDataModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

autoPtr<transferDataModel> transferDataModel::New
(
    const dictionary& dict,
    cfdemCloud& sm,
    word transferDataType
)
{
    Info<< "Selecting transferDataModel "
         << transferDataType << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(transferDataType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalError
            << "transferDataModel::New(const dictionary&, const spray&) : "
            << endl
            << "    unknown transferDataModelType type "
            << transferDataType
            << ", constructor not in hash table" << endl << endl
            << "    Valid transferDataModel types are :"
            << endl;
        Info<< dictionaryConstructorTablePtr_->toc()
            << abort(FatalError);
    }

    return autoPtr<transferDataModel>(cstrIter()(dict,sm));
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
