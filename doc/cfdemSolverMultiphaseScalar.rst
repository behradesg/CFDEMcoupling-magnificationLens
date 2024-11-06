.. index:: cfdemSolverMultiphaseScalar

cfdemSolverMultiphaseScalar command
===================================

Description
"""""""""""


"cfdemSolverMultiphaseScalar" is a coupled CFD-DEM solver using the CFDEMcoupling framework. Based on the OpenFOAM solver multiphaseInterFoam\ |reg|\ (*) it has functionality to simulate several fluids using the Volume of Fluid approach, coupled with the DEM code LIGGGHTS for solid particles. Additionally, it enable evaluation of temperature and dissolved species concentration fields.


.. |reg|    unicode:: U+000AE .. REGISTERED SIGN

For more details, see :ref:`Vångö et al. (2018) <Vångö2018>` and :ref:`Nijssen et al. (2021) <Nijssen2021>`.


----------


.. _Vångö2018:



**(Vångö2018)** M. Vångö, S. Pirker, T. Lichtenegger. (2018):
"Unresolved CFD-DEM modeling of multiphase flow in densely packed particle beds",
Applied Mathematical Modelling

.. _Nijssen2021:



**(Nijssen2021)** T.M.J. Nijssen, J.A.M. Kuipers, J. van der Stel, A.T. Adema, K.A. Buist. (2021):
"article title here",
journal name here


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
