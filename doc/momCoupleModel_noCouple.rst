.. index:: momCoupleModel off

momCoupleModel off command
==========================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   momCoupleModels
   (
       off
   );

Examples
""""""""


.. parsed-literal::

   momCoupleModels
   (
       off
   );

Description
"""""""""""

The *off* model is a dummy momCoupleModel model providing a no momentum source
term for the CFD solver.

Restrictions
""""""""""""


Only for solvers that include no momentum exchange, e.g. immersed boundary.

Related commands
""""""""""""""""

:doc:`momCoupleModel <momCoupleModel>`

