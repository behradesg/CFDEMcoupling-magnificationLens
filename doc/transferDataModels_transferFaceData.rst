.. index:: transferDataModels (transferFaceData)

transferDataModels (transferFaceData) command
========================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   transferDataModels (transferFaceData);
   transferFaceDataProps
   {
     magnificationLensPatchIDArrayNames ( patchIDArrayName );      			    
     magnificationLensBoundaryPatchNames ( patchName );
   }

* *patchIDArrayName* = name of patch face ids array produced by writePatchFaceGlobalIDsList utility of magnification lens solver
* *patchName* = patch name


Examples
""""""""


.. parsed-literal::

   transferDataModels (transferFaceData);
   transferFaceDataProps
   {
     magnificationLensPatchIDArrayNames ( patchFaceGlobalIDs_magLens_bottom_master );      			    
     magnificationLensBoundaryPatchNames ( magLens_bottom_master );
   }

Description
"""""""""""

This model transfers patch face ids and fluxes to LIGGGHTS.

Restrictions
""""""""""""
This model requires alphaRhoPhi.particles field from magnification lens solver.

Related commands
""""""""""""""""

:doc:`transferDataModels <transferDataModels>`

