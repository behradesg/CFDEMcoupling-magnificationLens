.. index:: forceModel dSauter

forceModel dSauter command
==========================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       dSauter
   );
   dSauterProps
   {
       coarseGrainingFactors
       (
           X Y Z
       );
   }

* *coarseGrainingFactors* = list of coarse graining factors by type, separated by
  whitespace, optional


Description
"""""""""""

This "force model" does not influence the particles or the flow - it calculates
the Sauter diameter

.. image:: Eqs/d32.png
   :align: center

.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

