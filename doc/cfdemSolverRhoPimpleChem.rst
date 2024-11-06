.. index:: cfdemSolverRhoPimpleChem

cfdemSolverRhoPimpleChem command
================================

Description
"""""""""""


"cfdemSolverRhoPimpleChem" is a coupled CFD-DEM solver using the CFDEMcoupling
framework. Based on the OpenFOAM\ |reg|\ (*) solver rhoPimpleFoam, this is a
transient solver for compressible flow using the flexible PIMPLE (PISO-SIMPLE)
algorithm, coupled with the DEM code LIGGGHTS for solid particles.
Compared to cfdemSolverRhoPimple this solver adds functionality for chemical
reactions.

.. |reg|    unicode:: U+000AE .. REGISTERED SIGN


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
