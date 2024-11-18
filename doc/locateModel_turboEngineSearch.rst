.. index:: locateModel turboEngine

locateModel turboEngine command
===============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   locateModel turboEngine;
   turboEngineProps
   {
       treeSearch switch1;
   }

* *switch1* = switch to use tree search algorithm


Examples
""""""""


.. parsed-literal::

   locateModel turboEngine;
   turboEngineProps
   {
       treeSearch true;
   }

Description
"""""""""""

The locateModel *turboEngine* locates the CFD cell and cellID corresponding to a
given position. The algorithm is improved compared to engine search to show
better parallel performance.

The turboEngineSearch locate Model can be used with different settings to use
different algorithms:

* faceDecomp false; treeSearch false;  will execute some geometric (linear) search
  using the last known cellID
* faceDecomp false; treeSearch true;   will use a recursive tree structure to find
  the cell. (recommended)


Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`locateModel <locateModel>`

