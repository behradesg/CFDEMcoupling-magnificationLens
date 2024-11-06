.. index:: averagingModel dilute

averagingModel dilute command
=============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   averagingModel dilute;

Examples
""""""""


.. parsed-literal::

   averagingModel dilute;

Description
"""""""""""

The averaging model performs the Lagrangian->Eulerian mapping of data (e.g.
particle velocities).
In the "cfdemParticle cloud" this averaging model is used to calculate the
average particle velocity inside a CFD cell. The *dilute* model is supposed to
be applied to cases where the granular regime is rather dilute. The particle
velocity inside a CFD cell is evaluated from a single particle in a cell (no
averaging).

Restrictions
""""""""""""


This model is computationally efficient but should only be used when only one
particle is inside one CFD cell.

Related commands
""""""""""""""""

:doc:`averagingModel <averagingModel>`, :doc:`dense <averagingModel_dense>`

