.. index:: locateModel

locateModel command
===================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   locateModel model;

* model = name of the locateModel to be applied

Examples
""""""""


.. parsed-literal::

   locateModel engine;

.. note::

   This examples list might not be complete - please look for other models
   (locateModel XY) in this documentation.

Description
"""""""""""

The locateModel is the base class for models which search for the CFD cell and
cellID corresponding to a position. In general it is used to find the cell a
particle is located in.

Restrictions
""""""""""""


none

Default
"""""""

none

