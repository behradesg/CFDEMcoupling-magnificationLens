.. index:: forceModel DiFeliceDrag

forceModel DiFeliceDrag command
===============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       DiFeliceDrag
   );
   DiFeliceDragProps
   {
       velFieldName          "U";
       voidfractionFieldName "voidfraction";
       granVelFieldName      "Us";
       scale                 scalar1;
       scaleDrag             scalar2;
       treatForceExplicit    switch1;
       implForceDEM          switch2;
       verbose               switch3;
       interpolation         switch4;
       scalarViscosity       switch5;
   }

* *U* = name of the finite volume fluid velocity field
* *voidfraction* = name of the finite volume void fraction field
* *Us* = name of the finite volume granular velocity field
* *scalar1* = (optional) scaling of particle diameter: d\_sim=scale\*d\_real. d\_sim=(potentially coarse-grained) particle diameter.
  scale=coarse-graining factor. d\_real= particle diameter as it is measured.
* *scalar2* = (optional) scaling factor which directly scales the drag force.
* *switch1* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch2* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch3* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch4* = (optional, default false) flag to use interpolated void fraction and velocity values
* *switch5* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       DiFeliceDrag
   );
   DiFeliceDragProps
   {
       velFieldName  "U";
       interpolation true;
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *DiFeliceDrag* model is a
model that calculates the particle based drag force following the correlation of
Di Felice (see Zhou et al. (2010), JFM).

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

