.. index:: forceModel viscForce

forceModel viscForce command
============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       viscForce;
   );
   viscForceProps
   {
       velocityFieldName  "U";
       useAddedMass       scalar1;
       treatForceExplicit switch1;
       treatForceDEM      switch2;
       interpolation      switch3;
       scalarViscosity    switch4;
   }

* *U* = name of the finite volume fluid velocity field
* *scalar1* = (optional, default 0) coefficient of added mass accounted for
* *switch1* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch2* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch3* = (optional, default false) flag to use interpolated stress values
* *switch4* =  (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       viscForce;
   );
   viscForceProps
   {
       velocityFieldName "U";
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *viscForce* model
calculates the particle based viscous force, -(grad(tau)) \* Vparticle
(see Zhou et al. (2010): "Discrete particle simulation of particle-fluid flow:
model formulations and their applicability", J. Fluid Mech.).

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

