.. index:: momCoupleModel explicitCouple

momCoupleModel explicitCouple command
=====================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   momCoupleModels
   (
       explicitCouple
   );
   explicitCoupleProps
   {
       fLimit vector;
   }

* *vector* = limiter vector for explicit force term (default (1e10,1e10,1e10) )


Examples
""""""""


.. parsed-literal::

   momCoupleModels
   (
       explicitCouple
   );
   explicitCoupleProps
   {
       fLimit (1e3 1e2 1e4);
   }

Description
"""""""""""

The *explicitCouple* model is a momCoupleModel model providing an explicit
momentum source term for the CFD solver.

Restrictions
""""""""""""


Only for solvers that include explicit momentum exchange.

Related commands
""""""""""""""""

:doc:`momCoupleModel <momCoupleModel>`

