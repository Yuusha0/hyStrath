# hyStrath for OpenFOAM-v6

#### Hypersonic / Rarefied gas dynamics code developments released under license GPL-3.0 
#### The only platform to conjointly host open-source CFD and DSMC codes designed for atmospheric re-entry analysis

#### Includes:
+ *hyFoam* CFD solver (supersonic combusting flows)  
+ *hy2Foam* CFD solver (hypersonic reacting flows)  

#### Please visit the [_hyStrath_ Wiki page](https://github.com/vincentcasseau/hyStrath/wiki)  

<br><br>

---  
## Compatibility, Maintenance, Installation and Sync

### OpenFOAM-6 branch

#### Compatibility  
+ OF-v6: https://openfoam.org/release/6/
+ OF-v5: https://openfoam.org/release/5-0/

#### Installation  
```sh
git clone https://github.com/Yuusha0/hyStrath.git --branch OpenFOAM-6 --single-branch && cd hyStrath/  
./install-all.sh np > logInstall 2>&1 &
```  

where _np_ is the number of processors to be used during the installation.  

#### [View more](https://github.com/vincentcasseau/hyStrath/wiki/Compatibility,-Maintenance,-Installation-and-Sync)  

<br><br>

---  
## Release history
#### 5 Dec 2018: OpenFOAM-6 branch for CFD
+ New branch with CFD module compiling on OpenFOAM-6 and OpenFOAM-5

#### 29 Aug 2018: 'Concordia' release, Master branch  
+ Master branch ported to OpenFOAM v1706   
+ Minor DSMC corrections  
+ CFD and DSMC rearrangements for future integration of the hybrid solver  

#### [View more](https://github.com/vincentcasseau/hyStrath/wiki/Release-history)  


<br><br>

---  

## Publications

#### [How to cite original authors work](https://github.com/vincentcasseau/hyStrath/wiki/Publications#how-to-cite-our-work)  

#### Latest journal article:  
[*__dsmcFoam+__*] &nbsp; C. White _et al._, 03/2018: [dsmcFoam+: An OpenFOAM based direct simulation Monte Carlo solver](https://pure.strath.ac.uk/portal/files/81235392/White_etal_CPC_2017_an_OpenFOAM_based_direct_simulation_Monte_Carlo_solver.pdf)

#### Latest conference paper:  
[*__ARC__*] &nbsp; V. Renato _et al._, 09/2017: [Multi-dimensional Ablation and Thermal Response Program for Martian Entry
Analysis](https://strathprints.strath.ac.uk/62926)  

#### [View more](https://github.com/vincentcasseau/hyStrath/wiki/Publications)  


<br><br>

---  

## People & Contact for original hyStrath

__GitHub coordinator:__ Dr Vincent Casseau  

__Contributors:__ Dr Vincent Casseau, Daniel E.R. Espinoza, Dr Christopher J. Capon, Dr Jimmy-John O.E. Hoste, Dr Viola Renato, Dr Rodrigo C. Palharini, Dr Craig White, Dr Melrose Brown, Prof Russell R. Boyce, Dr Thomas J. Scanlon, Dr Richard E. Brown     

__External contributors:__ the Micro & Nano Flows Group, R.Tech Engineering   

#### [View more](https://github.com/vincentcasseau/hyStrath/wiki/People-and-Contact)  


<br><br>

---  
### _hyStrath_ also features  
+ **_blockMeshDG_** by Anton Kidess (https://openfoamwiki.net/index.php/Contrib_blockMeshDG)  
+ **_makeAxialMesh_** by Bernhard Gschaider (http://openfoamwiki.net/index.php/Contrib/MakeAxialMesh)
