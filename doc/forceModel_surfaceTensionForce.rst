.. index:: forceModel surfaceTensionForce

forceModel surfaceTensionForce command
======================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       surfaceTensionForce;
   );
   surfaceTensionForceProps
   {
       stfFieldName "surfaceTensionField";
   }

* *surfaceTensionField* = name of the surface tension force field


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       surfaceTensionForce;
   );
   surfaceTensionForceProps
   {
       stfFieldName "surfaceTensionForce";
   }

Description
"""""""""""

The force model calculates the surface tension force acting on each DEM particle
based on a pre-calculated surface tension force as V\_particle \* F\^sigma. When
used in conjunction with the :doc:`cfdemSolverMultiphase <cfdemSolverMultiphase>`
solver, the surface tension force is calculated with the CSF (continuum surface
force) model (see Brackbill et al. (1992): "A continuum method for modeling
surface tension", J. Comput. Phys.).

Restrictions
""""""""""""


Has to be used with a multiphase solver that calculates the surface tension
force, e.g. *cfdemSolverMultiphase*\ .

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`, :doc:`cfdemSolverMultiphase <cfdemSolverMultiphase>`

