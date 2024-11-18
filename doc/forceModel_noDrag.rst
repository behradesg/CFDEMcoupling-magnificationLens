.. index:: forceModel noDrag

forceModel noDrag command
=========================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       noDrag
   );

   noDragProps
   {
       noDEMForce;
       keepCFDForce;
       treatForceExplicit switch1;
   }

* *noDEMForce* = (optional, default false) do not apply the previously calculated forces in DEM integration
* *keepCFDForce* = (optional, default false) do not delete the previously calculated forces and use them in CFD source terms
* *switch1* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       noDrag
   )
   noDragProps
   {
       noDEMForce;
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *noDrag* model sets the
forces acting on the particle to zero. If several force models are selected and
noDrag is the last model being executed, the fluid particle force will be set to
zero. If the variable *noDEMForce* is set, then the forces communicated to the
DEM solver are also set to zero.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

