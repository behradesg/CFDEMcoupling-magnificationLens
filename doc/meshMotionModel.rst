.. index:: meshMotionModel

meshMotionModel command
=======================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   meshMotionModel model;

* model = name of the meshMotionModel to be applied

Examples
""""""""


.. parsed-literal::

   meshMotionModel noMeshMotion;

.. note::

   This examples list might not be complete - please look for other models
   (meshMotionModel XY) in this documentation.

Description
"""""""""""

The *meshMotionModel* is the base class for models which manipulate the CFD mesh
according to the DEM mesh motion.

Restrictions
""""""""""""


none

Default
"""""""

none

