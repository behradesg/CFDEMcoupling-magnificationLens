.. index:: locateModel engineSearchMany2Many

locateModel engineSearchMany2Many command
=========================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   locateModel engineSearchMany2Many;
   engineSearchMany2ManyProps
   {
       engineProps
       {
           treeSearch switch1;
       }
   }

*switch1* = switch to use tree search algorithm

Examples
""""""""


.. parsed-literal::

   locateModel engineSearchMany2Many;
   engineSearchMany2ManyProps
   {
       engineProps
       {
           treeSearch true;
       }
   }

Description
"""""""""""

The locateModel "engine" locates the CFD cell and cellID corresponding to a
given position.
This model is a dummy for the
:doc:`twoWayMany2Many dataExchangeModel <dataExchangeModel_twoWayMany2Many>` which
locates using the specified "engine" during coupling.

.. note::

   Using this model with any other dataExchangeModel will cause problems.

The *engineSearchMany2Many* locateModel can be used with different settings to
use different algorithms:

* treeSearch false;  will execute some geometric (linear) search using the last
  known cellID (recommended)
* treeSearch true;   will use a recursive tree structure to find the cell.


Restrictions
""""""""""""


Use only with the twoWayMany2Many dataExchangeModel!

Related commands
""""""""""""""""

:doc:`locateModel <locateModel>`

