.. index:: cfdemSolverPisoScalar

cfdemSolverPisoScalar command
=============================

Description
"""""""""""


"cfdemSolverPisoScalar" is a coupled CFD-DEM solver using CFDEMcoupling, an open
source parallel coupled CFD-DEM framework. Based on pisoFoam\ |reg|\ (*), a finite
volume based solver for turbulent Navier-Stokes equations applying PISO
algorithm, "cfdemSolverPisoScalar" has additional functionality for a coupling
to the DEM code "LIGGGHTS" as well as a scalar transport equation.

.. |reg|    unicode:: U+000AE .. REGISTERED SIGN

The volume averaged Navier-Stokes Equations are solved accounting for momentum
exchange and volume displacement of discrete particles, whose trajectories are
calculated in the DEM code LIGGGHTS.

The scalar transport equation is coupled to scalar properties of the particle
phase, thus convective heat transfer in a fluid granular system can be modeled
with "cfdemSolverPisoScalar".

For more details, see :ref:`Goniva et al. (2010) <Goniva2010>`. The heat transfer
equation is implemented according to :ref:`Nield and Bejan (2013) <Nield2013>`.


----------


.. _Goniva2010:



**(Goniva, 2010)** Goniva, C., Kloss, C., Hager, A. and Pirker, S. (2010):
"An Open Source CFD-DEM Perspective",
Proc. of OpenFOAM Workshop, Göteborg, June 22.-24.

.. _Nield2013:



**(Nield, 2013)** Nield, D. A. and Bejan, A. (2013):
"Convection in Porous Media", DOI 10.1007/978-1-4614-5541-7\_2, Springer


----------



.. note::

   (*) This offering is not approved or endorsed by OpenCFD Limited, producer
   and distributor of the OpenFOAM software via www.openfoam.com, and owner of
   the OPENFOAM\ |reg| and OpenCFD\ |reg| trade marks.
   OPENFOAM\ |reg| is a registered trade mark of OpenCFD Limited, producer and
   distributor of the OpenFOAM software via www.openfoam.com.

.. |reg|    unicode:: U+000AE .. REGISTERED SIGN


.. _lws: http://lammps.sandia.gov
.. _ld: Manual.html
.. _lc: Section_commands.html#comm
