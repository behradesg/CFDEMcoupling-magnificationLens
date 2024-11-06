.. index:: liggghtsCommandModels

liggghtsCommandModels command
=============================

Syntax
""""""

Defined in :ref:`liggghtsCommmands <liggghtsCommands>`
dictionary.


.. parsed-literal::

   liggghtsCommandModels
   (
       model_x
       model_y
   );

* model = name of the liggghtsCommandModel to be applied

Examples
""""""""


.. parsed-literal::

   liggghtsCommandModels
   (
      runLiggghts
      writeLiggghts
   );

.. note::

   This examples list might not be complete - please look for other models
   (liggghtsCommandModel XY) in this documentation.

Description
"""""""""""

The liggghtsCommandModel is the base class to execute DEM commands within a CFD
run.

Restrictions
""""""""""""


Works only with MPI coupling.

Default
"""""""

none

