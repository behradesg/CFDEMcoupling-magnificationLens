.. index:: cfdemSolverPimple

cfdemSolverPimple command
=========================

Description
"""""""""""


"cfdemSolverPimple" is a coupled CFD-DEM solver using CFDEMcoupling, an open-source parallel coupled CFD-DEM framework. Based on DPMFoam\ |reg|\ (*), a finite
volume based solver for turbulent Navier-Stokes equations applying the PIMPLE
algorithm, "cfdemSolverPimple" has additional functionality for a coupling to the
DEM code "LIGGGHTS".

.. |reg|    unicode:: U+000AE .. REGISTERED SIGN

The volume averaged Navier-Stokes Equations are solved accounting for momentum
exchange and volume displacement of discrete particles whose trajectories are
calculated in the DEM code LIGGGHTS.


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
