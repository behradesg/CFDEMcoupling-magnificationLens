# CFDEMcoupling-magnificationLens 

CFDEM®coupling stands for Computational Fluid Dynamics (CFD) - Discrete Element Method (DEM) coupling. It combines the open source packages OpenFOAM® (CFD) and LIGGGHTS® (DEM) to simulate particle-laden flows. CFDEM®coupling is part of the [CFDEM®project](https://www.cfdem.com).

[![CircleCI](https://circleci.com/gh/ParticulateFlow/CFDEMcoupling.svg?style=shield&circle-token=7e8118524babddbefccf4e3608a7545d405acbb4)](https://circleci.com/gh/ParticulateFlow/CFDEMcoupling)
[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0.html)

## Disclaimer

> This is an academic adaptation of the CFDEM®coupling software package, released by the
[Department of Particulate Flow Modelling at Johannes Kepler University in Linz, Austria.](https://www.jku.at/pfm)
> LIGGGHTS® and CFDEM® are registered trademarks, and this offering is not approved or
endorsed by DCS Computing GmbH, the official producer of the LIGGGHTS® and CFDEM®coupling software.
> This offering is not approved or endorsed by OpenCFD Limited, producer and distributor of the OpenFOAM software via www.openfoam.com, and owner of the OPENFOAM®  and OpenCFD®  trade marks.

## Features
This CFDEMcoupling version is designed to be compatible with magnification lens solver [(pfmFOAM-magnificationLens)](https://github.com/behradesg/pfmFOAM-magnificationLens). It includes a new force model for paticle velocity controller and new subforce model for deactivating fluid forces in defined cellsets. In addition, Laplace filter and a new diffusion smoothing models are available. Also, new data transfer models can be found. 

## How to cite
Behrad Esgandari, Daniel Queteschiner, Stefan Pirker, and Simon Schneiderbauer. "Discrete magnification lens model: A new hybrid multi-scale modelling method for fluid-particle systems." Powder Technology 445 (2024): 120094.

## Installation
The OpenFOAM 6 and LIGGGHTS [(LIGGGHTS-magnificationLens)](https://github.com/behradesg/LIGGGHTS-magnificationLens) compatible with CFDEMcoupling-magnificationLens should already be compiled in your system. Then, download the solver or clone it using git clone. Change the cloned folder name to CFDEMcoupling and place the folder in a folder named CFDEM. Load CFDEMcoupling bashrc in a terminal using,
```bash
cd CFDEM/CFDEMcoupling
source etc/bashrc
./Allwmake
```
Compile LIGGGHTS as a library,
```bash
cfdemComLIGlib
```
compile source files with,
```bash
cfdemCompCFDEMsrc 
```
compile solvers,
```bash
cfdemCompCFDEMsol
```

## Tutorial
The tutorials related to the CFD-DEM cases in Esgandari et al. (2024) can be found in CFDEMcoupling/tutorials/cfdemSolverPimple/DiscreteMagnificationLensPaperCases.

## License

[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0.html)

- This software is distributed under the [GNU General Public License](https://opensource.org/licenses/GPL-3.0).
- Copyright © 2009-     JKU Linz
- Copyright © 2012-2015 DCS Computing GmbH, Linz
- Some parts of CFDEM®coupling are based on OpenFOAM® and Copyright on these
  parts is held by the OpenFOAM® Foundation (www.openfoam.org)
  and potentially other parties.
- Some parts of CFDEM®coupling are contributed by other parties, which are
  holding the Copyright. This is listed in each file of the distribution.
