.. _1\_4:

Dictionaries
============

.. _couplingProperties:

couplingProperties dictionary
-----------------------------

**General:**

In the *couplingProperties* dictionary the setup of the coupling routines of the
CFD-DEM simulation are defined.

**Location:** $caseDir/CFD/constant

**Structure:**

The dictionary is divided into two parts, "sub-models & settings" and "sub-model
properties".

In "sub-models & settings" the following routines must be specified:

* modelType
* couplingInterval
* voidFractionModel
* locateModel
* meshMotionModel
* regionModel
* IOModel
* dataExchangeModel
* averagingModel
* forceModels
* momCoupleModels
* turbulenceModelType


In "sub-model properties" sub-dictionaries might be defined to specify model
specific parameters.

**Settings:**

Reasonable example settings for the *couplingProperties* dictionary are given in
the tutorial cases.


.. parsed-literal::

   modelType

*modelType* refers to the formulation of the equations to be solved. Choose "A",
"B" or "Bfull", according to :ref:`Zhou et al. (2010) <Zhou2010>`. Model "A" requires
the use of the force models gradPForce and viscForce, whereas "B" requires the
force model "Archimedes". "Bfull" refers to model type I.


.. parsed-literal::

   couplingInterval

The coupling interval determines the time passing between two CFD-DEM data
exchanges.

A useful procedure would be:

#. Set the DEM time step in the LIGGGHTS input file according to the needs of the
   pure DEM problem.
#. Set the *couplingInterval*\ , which refers to the DEM time steps. Depending on the
   problem you will need to have a close (small couplingInterval) or loose
   coupling.
#. Choose the CFD time step in the controlDict. It must be equal to or smaller than
   the coupling time, otherwise you will get the error: "Error - TS bigger than
   coupling interval!".

**Example:**

Choosing DEMts=0.00001s and couplingInterval=10 means that an exchange of data
(=coupling) will happen every 0.0001s.


----------


.. _liggghtsCommands:

liggghtsCommands dictionary
---------------------------

**General:**

In the *liggghtsCommands* dictionary LIGGGHTS commands which are to be executed
during a coupled CFD-DEM simulation are specified.

**Location:** $caseDir/CFD/constant

**Structure:**

The dictionary is divided into two parts, first a list of
:ref:`liggghtsCommandModels <lcm>` is defined, then the
settings for each model must be specified.

**Settings:**

Reasonable example settings for the *liggghtsCommands* dictionary are given in
the tutorial cases.


----------


.. _Zhou2010:



**(Zhou, 2010)**
"Discrete particle simulation of particle-fluid flow: model formulations and their applicability",
Zhou, Z. Y., Kuang, S. B., Chu, K. W. and Yu, A. B., J. Fluid Mech., 661, pp. 482-510 (2010)

