.. index:: IOModel sophIO

IOModel sophIO command
======================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   IOModel sophIO;

Examples
""""""""


.. parsed-literal::

   IOModel sophIO;

Description
"""""""""""

The *sophIO* model is based on the :doc:`basicIO <IOModel_basicIO>` model and
additionally writes void fraction, implicit forces and explicit forces.

Data is written every write time of the CFD simulation.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`IOModel <IOModel>`, :doc:`IOModel basicIO <IOModel_basicIO>`

