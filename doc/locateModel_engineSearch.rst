.. index:: locateModel engine

locateModel engine command
==========================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   locateModel engine;
   engineProps
   {
       treeSearch switch1;
   }

* *switch1* = switch to use tree search algorithm


Examples
""""""""


.. parsed-literal::

   locateModel engine;
   engineProps
   {
       treeSearch true;
   }

Description
"""""""""""

The locateModel *engine* locates the CFD cell and cellID corresponding to a
given position.
The *engine* locate Model can be used with different settings to use different
algorithms:

* treeSearch false;  will execute some geometric (linear) search using the last known cellID
* treeSearch true;   will use a recursive tree structure to find the cell (recommended).


Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`locateModel <locateModel>`

