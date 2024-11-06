.. index:: IOModel basicIO

IOModel basicIO command
=======================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   IOModel basicIO;

Examples
""""""""


.. parsed-literal::

   IOModel basicIO;
   serialOutput;
   cartesianOutput;

Description
"""""""""""

The *basicIO* model writes particle positions, velocities and radii to files.
The default output directory is *$casePath/CFD/proc\*/time/lagrangian*.

Using the keyword *serialOutput;* in the
:ref:`couplingProperties <couplingProperties>` dictionary,
the IO is serial to the directory *$casePath/CFD/lagrangian*\ . In this case
only the data on processor 0 is written!

Using the keyword *cartesianOutput;* in the
:ref:`couplingProperties <couplingProperties>` dictionary,
particle positions will be written as cartesian coordinates instead of
barycentric coordinates.

Data is written every write time of the CFD simulation.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`IOModel <IOModel>`

