/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2018-2019 Yuusha and tilasoldo
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of tabulatedThermophysicalProperties on OpenFOAM.
    It is based on chriss85 contribution for OpenFOAM 2.3.x.

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

\*---------------------------------------------------------------------------*/

#include "hTabularThermo.H"

// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

template<class EquationOfState>
inline Foam::hTabularThermo<EquationOfState>::hTabularThermo
(
    const EquationOfState& pt,
    const extrapolation2DTable<scalar> hfTable,
    const extrapolation2DTable<scalar> cpTable,
    const extrapolation2DTable<scalar> hTable,
    const scalar Hf
)
:
    EquationOfState(pt),
    hfTable(hfTable),
    cpTable(cpTable),
    hTable(hTable),
    Hf_(Hf)

{}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class EquationOfState>
inline Foam::hTabularThermo<EquationOfState>::hTabularThermo
(
    const hTabularThermo& pt
)
:
    EquationOfState(pt),
    hfTable(pt.hfTable),
    cpTable(pt.cpTable),
    hTable(pt.hTable),
    Hf_(pt.Hf_)
{}


template<class EquationOfState>
inline Foam::hTabularThermo<EquationOfState>::hTabularThermo
(
    const word& name,
    const hTabularThermo& pt
)
:
    EquationOfState(name, pt),
    hfTable(pt.hfTable),
    cpTable(pt.cpTable),
    hTable(pt.hTable),
    Hf_(pt.Hf_)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::limit
(
    const scalar T
) const
{
    return T;
}

template<class EquationOfState>
Foam::word Foam::hTabularThermo<EquationOfState>::hfModeToWord
(
     const hfMode& mode
) const
{
    word enumName("constant");

    switch (mode)
    {
        case hTabularThermo::constant:
        {
            enumName = "constant";
            break;
        }
       case hTabularThermo::tabulated:
        {
            enumName = "tabulated";
            break;
        }
    }

    return enumName;
}


template<class EquationOfState>
typename Foam::hTabularThermo<EquationOfState>::hfMode
Foam::hTabularThermo<EquationOfState>::wordToHfMode
(
    const word& mode
) const
{
    if (mode == "constant")
    {
        return hTabularThermo::constant;
    }
    else if (mode == "tabulated")
    {
        return hTabularThermo::tabulated;
    }
    else
    {
        WarningIn
        (
            "Foam::hTabularTHermo<EquationOfState>::wordToHfMode"
            "("
            "    const word&"
            ")"
        )
	    << "bad mode specifier " << mode << " using 'constant'" << endl;

        return hTabularThermo::constant;
    }
}

template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::cv_t
(
    const scalar p, const scalar Tt
) const
{
    return cpTable(Tt, p) - EquationOfState::cpMcv(p,Tt) + this->cv_r(p,Tt);
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::cv_r
(
    const scalar p, const scalar Tt
) const
{
    // No rotational mode for equilibrium chemistry
    return 0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::cv_v_mode
(
    const label vibMode,
    const scalar p,
    const scalar Tv
) const
{
    // No vibrational mode for equilibrium chemistry
    return 0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::cv_v
(
    const scalar p,
    const scalar Tv
) const
{
    // No vibrational mode for equilibrium chemistry
    return 0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::cv_el
(
    const scalar p,
    const scalar Tv
) const
{
    // No electronic mode for equilibrium chemistry
    return 0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::cv_e
(
    const scalar p,
    const scalar Tv
) const
{
    // No electron mode for equilibrium chemistry
    return 0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::ha
(
    const scalar p,
    const scalar Tt,
    const scalar Tv
) const
{
    return hTable(p, Tt) + hc();
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::ets
(
    const scalar p,
    const scalar Tt
) const
{
    // No trans-rotaional mode for equilibrium chemistry
    return 0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::ers
(
    const scalar p,
    const scalar Tt
) const
{
    // No rotational mode for equilibrium chemistry
    return 0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::evs_mode
(
    const label vibMode,
    const scalar p,
    const scalar Tv
) const
{
    // No vibrational mode for equilibrium chemistry
    return 0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::evs
(
    const scalar p,
    const scalar Tv
) const
{
    // No vibrational mode for equilibrium chemistry
    return 0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::eels
(
    const scalar p,
    const scalar Tv
) const
{
    // No electronic mode for equilibrium chemistry
    return 0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::ees
(
    const scalar p,
    const scalar Tv
) const
{
    // No electron mode for equilibrium chemistry
    return 0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::zetar
(
    const scalar p, 
    const scalar Tt, 
    const scalar Tv
) const
{
    // No rotational energy for equilibrium chemistry
    return 0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::zetav_mode
(
    const label vibMode, 
    const scalar p, 
    const scalar Tv
) const
{
    // No vibrational energy for equilibrium chemistry
    return 0.0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::zetav
(
    const scalar p, 
    const scalar Tv
) const
{
    // No vibrational energy mode for equilibrium chemistry
    return 0.0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::zetael
(
    const scalar p, 
    const scalar Tv
) const
{
    // No electronic energy mode for equilibrium chemistry
    return 0.0;
}


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::zetae
(
    const scalar p, 
    const scalar Tv
) const
{
    // No electron energy for equilibrium chemistry
    return 0.0;
}

// DELETED according to hyFoam thermophysical models ***************************
// template<class EquationOfState>
// inline Foam::scalar Foam::hTabularThermo<EquationOfState>::Hs
// (
//     const scalar p, const scalar T
// ) const
// {
//     // Switch according constant or tabulated heat of formation
//     switch(mode_)
//     {
//     case hTabularThermo::constant:
// 	{
// 	    return Ha(p, T) - Hc();
// 	}

//     case hTabularThermo::tabulated:
// 	{
// 	    return Ha(p, T) - hfTable(p, T);
// 	}
//     }

//     return 0;
// }


template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::hc()
const
{
    // Switch according constant or tabulated heat of formation
    switch(mode_)
    {
        case hTabularThermo::constant:
	{
	    return Hf_;
	}
    
	// Do not use Hc when using tabulated heat of formation
        case hTabularThermo::tabulated:
	{
	    return 0;
	}
    }
    
    return 0;
}

template<class EquationOfState>
inline Foam::scalar Foam::hTabularThermo<EquationOfState>::s
(
    const scalar p,
    const scalar Tt,
    const scalar Tv
) const
{
    notImplemented
    (
        "scalar hTabularThermo<EquationOfState>::"
        "s(const scalar p, const scalar T) const"
    );
    return Tt;
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class EquationOfState>
inline Foam::hTabularThermo<EquationOfState>&
Foam::hTabularThermo<EquationOfState>::operator=
(
    const hTabularThermo<EquationOfState>& pt
)
{
    EquationOfState::operator=(pt);

    hfTable = pt.hfTable;
    cpTable = pt.cpTable;
    hTable = pt.hTable;
    Hf_ = pt.Hf_;

    return *this;
}


template<class EquationOfState>
inline void Foam::hTabularThermo<EquationOfState>::operator+=
(
    const hTabularThermo<EquationOfState>& pt
)
{
    scalar Y1 = this->nMoles();

    EquationOfState::operator+=(pt);

    if (mag(this->nMoles()) > SMALL)
    {
        Y1 /= this->nMoles();
        const scalar Y2 = pt.nMoles()/this->nMoles();

        hfTable = Y1*hfTable + Y2*pt.hfTable;
        cpTable = Y1*cpTable + Y2*pt.cpTable;
        hTable = Y1*hTable + Y2*pt.hTable;
	Hf_ = Y1*Hf_ + Y2*pt.Hf_;
    }
}


template<class EquationOfState>
inline void Foam::hTabularThermo<EquationOfState>::operator*=
(
    const scalar s
)
{
    EquationOfState::operator*=(s);
}


// * * * * * * * * * * * * * * * Friend Operators  * * * * * * * * * * * * * //

template<class EquationOfState>
inline Foam::hTabularThermo<EquationOfState> Foam::operator+
(
    const hTabularThermo<EquationOfState>& pt1,
    const hTabularThermo<EquationOfState>& pt2
)
{
    EquationOfState eofs = pt1;
    eofs += pt2;

    if (mag(eofs.nMoles()) < SMALL)
    {
        return hTabularThermo<EquationOfState>
        (
            eofs,
            pt1.hfTable,
            pt1.cpTable,
            pt1.hTable,
	    pt1.Hf_
        );
    }
    {
        const scalar Y1 = pt1.nMoles()/eofs.nMoles();
        const scalar Y2 = pt2.nMoles()/eofs.nMoles();

        return hTabularThermo<EquationOfState>
        (
            eofs,
            Y1*pt1.hfTable + Y2*pt2.hfTable,
            Y1*pt1.cpTable + Y2*pt2.cpTable,
            Y1*pt1.hTable + Y2*pt2.hTable,
	    Y1*pt1.Hf_ + Y2*pt2.Hf_
        );
    }
}


template<class EquationOfState>
inline Foam::hTabularThermo<EquationOfState> Foam::operator*
(
    const scalar s,
    const hTabularThermo<EquationOfState>& pt
)
{
    return hTabularThermo<EquationOfState>
    (
        s*static_cast<const EquationOfState&>(pt),
        pt.hfTable,
	pt.cpTable,
	pt.hTable,
	pt.Hf_
    );
}


template<class EquationOfState>
inline Foam::hTabularThermo<EquationOfState> Foam::operator==
(
    const hTabularThermo<EquationOfState>& pt1,
    const hTabularThermo<EquationOfState>& pt2
)
{
    EquationOfState eofs
    (
        static_cast<const EquationOfState&>(pt1)
     == static_cast<const EquationOfState&>(pt2)
    );

    const scalar Y1 = pt1.nMoles()/eofs.nMoles();
    const scalar Y2 = pt2.nMoles()/eofs.nMoles();

    return hTabularThermo<EquationOfState>
    (
        eofs,
        Y2*pt2.hfTable - Y1*pt1.hfTable,
        Y2*pt2.cpTable - Y1*pt1.cpTable,
        Y2*pt2.hTable  - Y1*pt1.hTable,
	Y2*pt2.Hf_ - Y1*pt1.Hf_
    );
}


// ************************************************************************* //
