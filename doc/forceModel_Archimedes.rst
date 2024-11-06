.. index:: forceModel Archimedes

forceModel Archimedes command
=============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       Archimedes
   );
   ArchimedesProps
   {
       gravityFieldName   "gravity";
       treatForceExplicit switch1;
       treatForceDEM      switch2;
   }

* *gravity* = name of the finite volume gravity field
* *switch1* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch2* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       Archimedes
   );
   ArchimedesProps
   {
       gravityFieldName "g";
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *Archimedes* model is a
model that calculates the Archimedes' volumetric lift force stemming from
density difference of fluid and particle.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

