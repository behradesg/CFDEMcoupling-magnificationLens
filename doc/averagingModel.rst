.. index:: averagingModel

averagingModel command
======================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   averagingModel model;

* model = name of averaging model to be applied

Examples
""""""""


.. parsed-literal::

   averagingModel dense;
   averagingModel dilute;

.. note::

   This examples list might not be complete - please look for other averaging
   models in this documentation.

Description
"""""""""""

The averaging model performs the Lagrangian->Eulerian mapping of data (e.g.
particle velocities).

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`dense <averagingModel_dense>`, :doc:`dilute <averagingModel_dilute>`

Default
"""""""

none

