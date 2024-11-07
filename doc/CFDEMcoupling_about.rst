.. _1\_1:

About CFDEMcoupling
===================


CFDEMcoupling provides an open-source parallel coupled CFD-DEM framework
combining the strengths of the `LIGGGHTS <http://www.cfdem.com>`_ DEM code and
the open-source CFD package OpenFOAM\ |reg|\ (*).
The CFDEMcoupling toolbox allows to expand standard CFD solvers of
OpenFOAM\ |reg|\ (*) to include a coupling to the DEM code
`LIGGGHTS <http://www.cfdem.com>`_.

In this toolbox the particle representation within the CFD
solver is organized by "cloud" classes. Key functionalities are organized in
sub-models (e.g. force models, data exchange models, etc.) which can easily be
selected and combined by dictionary settings.

The coupled solvers run fully parallel on distributed-memory clusters. Features
are:

* its modular approach allows users to easily implement new models
* its MPI parallelization enables to use it for large scale problems
* the `forum <lig_>`_ on CFD-DEM gives the possibility to exchange with other users / developers
* the use of Git allows to easily update to the latest version
* basic documentation is provided


The project structure:

* *src* directory including the source files of the coupling toolbox and models
* *applications* directory including the solver files for coupled CFD-DEM simulations
* *doc* directory including the documentation of CFDEMcoupling
* *tutorials* directory including basic tutorial cases showing the functionality


Details on installation are given in the :doc:`Installation <CFDEMcoupling_install>`
section.
The functionality of this CFD-DEM framework is described via :doc:`tutorial cases <CFDEMcoupling_tutorials>` showing how to use different solvers and
models.

CFDEMcoupling stands for Computational Fluid Dynamics (CFD) - Discrete Element
Method (DEM) coupling.

CFDEMcoupling is an open-source code, distributed freely under the terms of the
`GNU Public License (GPL) <https://www.gnu.org/licenses/gpl-3.0.en.html>`_.

Core development of the public version of CFDEMcoupling is done by Christoph
Goniva and Christoph Kloss, both at DCS Computing GmbH.

The original version of this documentation was written by Christoph Goniva, DCS
Computing GmbH, 2012.


----------



.. note::

   (*) This offering is not approved or endorsed by OpenCFD Limited, producer
   and distributor of the OpenFOAM software via www.openfoam.com, and owner of
   the OPENFOAM\ |reg| and OpenCFD\ |reg| trade marks.
   OPENFOAM\ |reg| is a registered trade mark of OpenCFD Limited, producer and
   distributor of the OpenFOAM software via www.openfoam.com.

.. |reg|    unicode:: U+000AE .. REGISTERED SIGN

.. _of: http://www.openfoam.org
.. _lig: http://www.cfdem.com

