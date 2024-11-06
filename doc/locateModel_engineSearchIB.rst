.. index:: locateModel engineIB

locateModel engineIB command
============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   locateModel engineIB;
   engineIBProps
   {
       engineProps
       {
           treeSearch switch1;
       }
       zSplit  value1;
       xySplit value2;
   }

* *switch1* = names of the finite volume scalar fields to be temporally averaged
* *value1* = number of z-normal layers for satellite points
* *value2* = number of satellite points in each layer


Examples
""""""""


.. parsed-literal::

   locateModel engineIB;
   engineIBProps
   {
       engineProps
       {
           treeSearch false;
       }
       zSplit  8;
       xySplit 16;
   }

Description
"""""""""""

The locateModel *engineIB* locates the CFD cell and cellID corresponding to a
given position. This locate model is especially designed for parallel immersed
boundary method. Each particle is represented by "satellite points" if it is
distributed over several processors.

The *engineIB* locate Model can be used with different settings to use different
algorithms:

* treeSearch false;  will execute some geometric (linear) search using the last known cellID (recommended)
* treeSearch true;   will use a recursive tree structure to find the cell.


This model is a modification of the *engine* search model. Instead of using the
centre-cell as starting point for the engine search, further satellite points
located on the surface of the sphere are checked. This ensures that (parts of)
spheres can be located even when their centre is on another processor. This is
especially important for parallel computations, when a sphere is about to move
from one processor to another.

Restrictions
""""""""""""


Only for immersed boundary solvers!

Related commands
""""""""""""""""

:doc:`locateModel <locateModel>`

