#!/bin/sh
cd ${0%/*} || exit 1    # Run from this directory

set -e

# copy new files --------------------------------------------------------------
cp -r $currentDir/src $sendingDir/
cp -r $currentDir/applications $sendingDir/
cp -r $currentDir/run $sendingDir/


# compile new libraries -------------------------------------------------------
cd $sendingDir/src/lagrangian/regionsAndInterfaces/
wclean libso
wmake -j$nProcs libso

cd $sendingDir/src/lagrangian/pic/
wclean libso
wmake -j$nProcs libso


# compile new executables ------------------------------------------------------
#---- solver ----
cd $sendingDir/applications/solvers/hybridMethods/pdFoam
wclean
wmake -j$nProcs

#---- utilities ----
cd $sendingDir/applications/utilities/preProcessing/hybrid/pdInitialise/
wclean all
wmake -j$nProcs all


# re-set to the initial directory ---------------------------------------------
cd $currentDir

echo "
Hybrid module PIC-DSMC $WM_PROJECT_VERSION compiled successfully. Hope you'll enjoy it, $userName :)
"
