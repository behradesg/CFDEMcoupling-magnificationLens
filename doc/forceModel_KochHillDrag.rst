.. index:: forceModel KochHillDrag

forceModel KochHillDrag command
===============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       KochHillDrag
   );
   KochHillDragProps
   {
       velFieldName            "U";
       voidfractionFieldName   "voidfraction";
       granVelFieldName        "Us"
       treatForceExplicit      switch1;
       implForceDEM            switch2;
       verbose                 switch3;
       interpolation           switch4;
       implForceDEMaccumulated switch5;
       scalarViscosity         switch6;
   }

* *U* = name of the finite volume fluid velocity field
* *voidfraction* = name of the finite volume void fraction field
* *Us* = (optional, default "Us") name of finite volume granular velocity field
* *switch1* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch2* = (optional, default false) flag to use implicit formulation of drag on DEM side
* *switch3* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch4* = (optional, default false) flag to use interpolated void fraction and fluid velocity values
* *switch5* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch6* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       KochHillDrag
   );
   KochHillDragProps
   {
       velFieldName "U";
       voidfractionFieldName "voidfraction";
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *KochHillDrag* model is a
model that calculates the particle based drag force following the correlation of
Koch & Hill (2001) (see van Buijtenen et al. (2011): "Numerical and experimental
study on multiple-spout fluidized beds", ChemEngScience).

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

