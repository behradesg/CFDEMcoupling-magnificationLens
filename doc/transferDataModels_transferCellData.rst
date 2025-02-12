.. index:: transferDataModels (transferCellData)

transferDataModels (transferCellData) command
========================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   transferDataModels (transferCellData);
   transferCellDataProps
   {
       magnificationLensBoundaryPatchNames ( patchName );
   }
* *patchName* = patch name


Examples
""""""""

.. parsed-literal::

   transferDataModels (transferCellData);
   transferCellDataProps
   {
       magnificationLensBoundaryPatchNames ( magLens_bottom_slave );
   }

Description
"""""""""""

This model transfers boundary cells data e.g. Us, granular temperature and diagonal components 
of particle stress tensor of magnification lens cellset in OF to LIGGGHTS.

Restrictions
""""""""""""
This model requires U.particles, Theta.particles, alpha.particles, P_XX.particles, 
P_YY.particles, P_ZZ.particles fields from magnification lens solver.

Related commands
""""""""""""""""

:doc:`transferDataModels <transferDataModels>`

