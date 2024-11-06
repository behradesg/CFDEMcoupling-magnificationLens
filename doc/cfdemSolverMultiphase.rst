.. index:: cfdemSolverMultiphase

cfdemSolverMultiphase command
=============================

Description
"""""""""""


"cfdemSolverMultiphase" is a coupled CFD-DEM solver using the CFDEMcoupling framework. Based on the OpenFOAM solver multiphaseInterFoam\ |reg|\ (*) it has functionality to simulate several fluids using the Volume of Fluid approach, coupled with the DEM code LIGGGHTS for solid particles.

.. |reg|    unicode:: U+000AE .. REGISTERED SIGN

For more details, see :ref:`Vångö et al. (2018) <Vångö2018>`.

.. warning::

   This solver requires OpenFOAM 4.x or 5.x to work properly.


----------


.. _Vångö2018:



**(Vångö2018)** M. Vångö, S. Pirker, T. Lichtenegger. (2018):
"Unresolved CFD-DEM modeling of multiphase flow in densely packed particle beds",
Applied Mathematical Modelling


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
