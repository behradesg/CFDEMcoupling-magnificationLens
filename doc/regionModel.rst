.. index:: regionModel

regionModel command
===================

.. note::

   In the current CFDEMcoupling version, this model is no longer used.

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.

Syntax
""""""


.. parsed-literal::

   regionModel model;

* model = name of the regionModel to be applied

Examples
""""""""


.. parsed-literal::

   regionModel allRegion;

.. note::

   This examples list might not be complete - please look for other models
   (regionModel XY) in this documentation.

Description
"""""""""""

The *regionModel* is the base class for region models to select a certain region
for coupled simulation.

Restrictions
""""""""""""


none

Default
"""""""

none

