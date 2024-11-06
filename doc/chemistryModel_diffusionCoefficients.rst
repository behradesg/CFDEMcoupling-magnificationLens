.. index:: chemistryModel diffusionCoefficients

chemistryModel diffusionCoefficients command
============================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   chemistryModels
   (
       diffusionCoefficients
   );
   diffusionCoefficientsProps
   {
       verbose             switch1;
       ChemistryFile       "$casePath/CFD/constant/foam.inp";
       diffusantGasNames   ( speciesNames );
   }

* *switch1* = (optional, default false) flag to output verbose information
* *ChemistryFile* = path to file, where the reacting species are listed
* *diffusantGasNames* = list of gas field names that are the reactant gases


Examples
""""""""


.. parsed-literal::

   chemistryModels
   (
       diffusionCoefficients
   );
   diffusionCoefficientsProps
   {
       verbose             false;
       ChemistryFile       "$casePath/CFD/constant/foam.inp";
       diffusantGasNames   (    CO
                                H2
                           );
   }

Description
"""""""""""

The chemistry model performs the calculation of chemical reactional effects
acting on each DEM particle. The diffusionCoefficients model activates the
binary molecular diffusion calculation of the reacting species using the
Fuller-Schettler-Giddings correlation.

Restrictions
""""""""""""


The :doc:`species <chemistryModel_species>` model needs to be active.

Related commands
""""""""""""""""

:doc:`chemistryModel <chemistryModel>`,
:doc:`chemistryModel species <chemistryModel_species>`

