
// --- Solve energy, INVISCID
//- NOTE VINCENT: aByU is equivalent to the original (a_pos*U_pos + a_neg*U_neg)
surfaceScalarField sigmaDotU
(
    "sigmaDotU",
    (
        fvc::interpolate(muEff)*mesh.magSf()*fvc::snGrad(U)
      + fvc::dotInterpolate(mesh.Sf(), tauMC)
    )
  & aByU
);

fvScalarMatrix EEqn
(
    fvm::ddt(rhoE)
  + fvc::div(phiEp)
  - fvc::div(sigmaDotU)
 ==
    reaction->Sh()
  + fvOptions(true,rhoE,rho)
);

fvOptions.constrain(EEqn);

EEqn.solve();

e = rhoE/rho - 0.5*magSqr(U);

et.ref() = e() - ev();
et.correctBoundaryConditions();
fvOptions.correct(rhoE);
e.boundaryFieldRef() = et.boundaryField() + ev.boundaryField();

rhoE.boundaryFieldRef() = rho.boundaryField()*(e.boundaryField() + 0.5*magSqr(U.boundaryField()));

