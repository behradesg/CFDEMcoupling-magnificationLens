.. index:: transferDataModels

transferDataModels command
=========================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   transferDataModels ( model );

* model = name of data trasnfer model to be applied

Examples
""""""""

.. parsed-literal::

   transferDataModels
   (
      transferFaceData
      transferCellData
   );

Description
"""""""""""

This model transfers data (e.g. face and cell ids) from OF to LIGGGHTS.

Restrictions
""""""""""""
none

Related commands
""""""""""""""""

:doc:`transferFaceData <transferDataModels_transferFaceData>`,
:doc:`transferCellData <transferDataModels_transferCellData>`

Default
"""""""

none

