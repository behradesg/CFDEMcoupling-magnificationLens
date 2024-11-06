.. index:: chemistryModels

chemistryModels command
=======================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   chemistryModels
   (
       model_x
       model_y
   );

* model = name of chemistry model to be applied

Examples
""""""""


.. parsed-literal::

   chemistryModels
   (
       species
       diffusionCoefficients
       massTransferCoeff
   );

Description
"""""""""""

The chemistry model initializes the required fields for the calculation of molar
fractions, determines the diffusion coefficients of the gaseous reactants,
calculates the necessary coefficients for the calculation of a mass transfer
coefficient. All models are executed sequentially. These values are used in the
DEM calculation of particle reduction models.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`diffusionCoefficient <chemistryModel_diffusionCoefficients>`,
:doc:`massTransferCoeff <chemistryModel_massTransferCoeff>`,
:doc:`species <chemistryModel_species>`

Default
"""""""

none

