.. index:: forceModel gradPForce

forceModel gradPForce command
=============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       gradPForce;
   );
   gradPForceProps
   {
       pFieldName         "pressure";
       velocityFieldName  "U";
       useAddedMass       scalar1;
       treatForceExplicit switch1;
       treatForceDEM      switch2;
       interpolation      switch3;
   }

* *pressure* = name of the finite volume fluid pressure field
* *U* = name of the finite volume fluid velocity field
* *scalar1* = (optional, default 0) coefficient of added mass accounted for
* *switch1* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch2* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch3* = (optional, default false) flag to use interpolated pressure values


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       gradPForce;
   );
   gradPForceProps
   {
       pFieldName        "p";
       velocityFieldName "U";
       interpolation     true;
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *gradPForce* model is a
model that calculates the particle based pressure gradient force -(grad(p)) \*
Vparticle (see Zhou et al. (2010): "Discrete particle simulation of
particle-fluid flow: model formulations and their applicability", J. Fluid Mech.).

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

