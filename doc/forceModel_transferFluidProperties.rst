.. index:: forceModel transferFluidProperties

forceModel transferFluidProperties command
==========================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       transferFluidProperties
   );
   transferFluidPropertiesProps
   {
       verbose       switch1;
       interpolation switch2;
   }

* *switch1* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch2* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details


Description
"""""""""""

This "force model" does not influence the particles or the flow - it transfer to fluid density and (dynamic)
viscosity from OpenFOAM to LIGGGHTS.

Restrictions
""""""""""""


This model requires *fix cfd/coupling/fluidproperties* to work.

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

