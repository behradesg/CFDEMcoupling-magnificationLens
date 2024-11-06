.. index:: cfdemSolverIBContinuousForcing

cfdemSolverIBContinuousForcing command
======================================

Description
"""""""""""

"cfdemSolverIBContinuousForcing" is a coupled CFD-DEM solver using CFDEMcoupling,
an open-source parallel coupled CFD-DEM framework, for calculating the dynamics
between immersed bodies and the surrounding fluid. Being an implementation of a
continuous forcing immersed boundary method it allows tackling problems where
the body diameter exceeds the maximal size of a fluid cell.


Using the toolbox of OpenFOAM\ |reg|\ (*) the governing equations of the fluid are
computed and the corrections of velocity and pressure field with respect to the
body-movement information, gained from LIGGGHTS, are incorporated.

.. |reg|    unicode:: U+000AE .. REGISTERED SIGN

The code of this solver was contributed by A.N. Balachandran Nair, JKU. For more
details, see :ref:`Balachandran Nair et al. (2021) <BalachandranNair2021>`

**Use:**

The solver is realized within the open-source framework CFDEMcoupling. Just as
for the unresolved CFD-DEM solver cfdemSolverPiso the file
CFD/constant/couplingProperties contains information about the settings for the
different models. While IOmodel, DataExchangeModel etc. are applicable for all
CFDEMcoupling-solvers, special locate-, force- and void fraction models were
designed for this solver:

:doc:`engineSearchIB <locateModel_engineSearchIB>`,
:doc:`ArchimedesIB <forceModel_ArchimedesIB>`,
:doc:`ShirgaonkarIB <forceModel_ShirgaonkarIB>`,
:doc:`IBVoidfraction <voidFractionModel_IBVoidFraction>`


----------


.. _BalachandranNair2021:



**(Balachandran Nair, 2021)** Balachandran Nair, A.N., Pirker, S. and Saeedipour, M.,
"Resolved CFD-DEM simulation of blood flow with a reduced-order RBC model",
Comp. Part. Mech. (2021)


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
