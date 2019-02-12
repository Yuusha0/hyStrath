#!/bin/bash

set -e

export userName=`whoami`

export currentDir=`pwd`
export buildDir=$currentDir/build
mkdir -p $buildDir

export sendingDir=$buildDir

nProcs=1
if [ $# -ne 0 ]
  then nProcs=$1;
fi
export nProcs

mkdir -p $sendingDir

./install-CFD.sh
#./install-DSMC.sh
#./install-hybridPICDSMC.sh
