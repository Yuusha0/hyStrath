/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2016 OpenFOAM Foundation
     \\/     M anipulation  | Copyright (C) 2016 OpenCFD Ltd.
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::functionObjects::specieReactionRates

Group
    grpFieldFunctionObjects

Description
    Writes the domain averaged reaction rates for each specie for each reaction
    into the file \<timeDir\>/specieReactionRates.dat

See also
    Foam::functionObjects::fvMeshFunctionObject
    Foam::functionObjects::volRegion
    Foam::functionObjects::writeFile

SourceFiles
    specieReactionRates.C

\*---------------------------------------------------------------------------*/

#ifndef functionObjects_specieReactionRates_H
#define functionObjects_specieReactionRates_H

#include "fvMeshFunctionObject.H"
#include "volRegion.H"
#include "writeFile.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace functionObjects
{

/*---------------------------------------------------------------------------*\
                     Class specieReactionRates Declaration
\*---------------------------------------------------------------------------*/

template<class ChemistryModelType>
class specieReactionRates
:
    public fvMeshFunctionObject,
    public volRegion,
    public writeFile
{
    // Private Member Data

        const ChemistryModelType& chemistryModel_;


    // Private Member Functions

        //- File header information
        virtual void writeFileHeader(Ostream& os) const;

        //- Disallow default bitwise copy construct
        specieReactionRates(const specieReactionRates&);

        //- Disallow default bitwise assignment
        void operator=(const specieReactionRates&);


public:

    //- Runtime type information
    TypeName("specieReactionRates");


    // Constructors

        //- Construct from Time and dictionary
        specieReactionRates
        (
            const word& name,
            const Time& runTime,
            const dictionary& dict
        );


    //- Destructor
    virtual ~specieReactionRates();


    // Member Functions

        //- Read the specieReactionRates data
        virtual bool read(const dictionary&);

        //- Do nothing
        virtual bool execute();

        //- Write the specie reaction rates
        virtual bool write();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace functionObjects
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
