.. index:: forceModel GidaspowDrag

forceModel GidaspowDrag command
===============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       GidaspowDrag
   );
   GidaspowDragProps
   {
       velFieldName          "U";
       voidfractionFieldName "voidfraction";
       granVelFieldName      "Us";
       phi                   scalar1;
       scale                 scalar2;
       scaleDrag             scalar3;
       switchingVoidfraction scalar4;
       treatForceExplicit    switch1;
       implForceDEM          switch2;
       verbose               switch3;
       interpolation         switch4;
       scalarViscosity       switch5;
   }

* *U* = name of the finite volume fluid velocity field
* *voidfraction* = name of the finite volume void fraction field
* *Us* = name of the finite volume cell averaged particle velocity field
* *scalar1* = drag correction factor (in doubt 1)
* *scalar2* = (optional, default 1.0) scaling of particle diameter: d\_sim=scale\*d\_real. d\_sim=(potentially coarse-grained) particle diameter. scale=coarse-graining factor. d\_real= particle diameter as it is measured.
* *scalar3* = (optional, default 1.0) scaling of drag law
* *scalar4* = (optional, default 0.8) void fraction above which dilute formulation will be used
* *switch1* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch2* = (optional, default false) flag to use implicit formulation of drag on DEM side
* *switch3* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch4* = (optional, default false) flag to use interpolated void fraction and fluid velocity values
* *switch5* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       GidaspowDrag
   );
   GidaspowDragProps
   {
       velFieldName          "U";
       voidfractionFieldName "voidfraction";
       granVelFieldName      "Us";
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *GidaspowDrag* model is a
model that calculates the particle based drag force following the correlation of
Gidaspow which is a combination of Ergun (1952) and Wen & Yu (1966)
(see Zhu et al. (2007): "Discrete particle simulation of particulate systems:
Theoretical developments", ChemEngScience).

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

