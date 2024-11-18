.. index:: IOModel

IOModel command
===============

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   IOModel model;

* model = name of IO-model to be applied

Examples
""""""""


.. parsed-literal::

   IOModel off;

.. note::

   This examples list might not be complete - please look for other IO models
   in this documentation.

Description
"""""""""""

*IOModel* is the base class to write data (e.g. particle properties) to files.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`IOModel basicIO <IOModel_basicIO>`, :doc:`IOModel off <IOModel_noIO>`,
:doc:`IOModel sophIO <IOModel_sophIO>`, :doc:`IOModel trackIO <IOModel_trackIO>`

Default
"""""""

none

