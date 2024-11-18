.. index:: forceModel SchillerNaumannDrag

forceModel SchillerNaumannDrag command
======================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       SchillerNaumannDrag
   );
   SchillerNaumannDragProps
   {
       velFieldName "U";
       treatForceExplicit switch1;
   }

* *U* = name of the finite volume fluid velocity field
* *switch1* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       SchillerNaumannDrag
   );
   SchillerNaumannDragProps
   {
       velFieldName "U";
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *SchillerNaumannDrag* model
is a model that calculates the particle based drag force following the
correlation of Schiller and Naumann.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

