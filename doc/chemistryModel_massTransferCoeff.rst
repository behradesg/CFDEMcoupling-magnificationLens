.. index:: chemistryModel massTransferCoeff

chemistryModel massTransferCoeff command
========================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   chemistryModels
   (
       massTransferCoeff
   );
   massTransferCoeffProps
   {
       verbose         switch1;
   }

* *switch1* = (optional, default false) flag to output verbose information


Examples
""""""""


.. parsed-literal::

   chemistryModels
   (
       massTransferCoeff
   );
   massTransferCoeffProps
   {
        verbose        false;
   }

Description
"""""""""""

The chemistry model performs the calculation of chemical reactional effects
acting on each DEM particle. The coefficients needed to calculate the mass
transfer coefficients are transferred to the DEM side, where it is used in the
*fix chem/shrink/core* module.

Restrictions
""""""""""""


The :doc:`species <chemistryModel_species>` model needs to be active.

Related commands
""""""""""""""""

:doc:`chemistryModel <chemistryModel>`,
:doc:`chemistryModel species <chemistryModel_species>`

