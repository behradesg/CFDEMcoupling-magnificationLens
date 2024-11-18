.. index:: chemistryModel species

chemistryModel species command
==============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   chemistryModels
   (
       species
   );
   speciesProps
   {
       ChemistryFile           "$casePath/CFD/constant/foam.inp";
       tempFieldName           "T";
       densityFieldName        "rho";
       voidfractionFieldName   "voidfraction";
       totalMoleFieldName      "molarConc";
       partTempName            "partTemp";
       partRhoName             "partRho";
       verbose                 switch1;
       Nevery                  number1;
   }

* *ChemistryFile* = path to file, where the reacting species are listed
* *T* = (optional, default "T") name of the finite volume temperature field
* *rho* = (optional, default "rho") name of the finite volume density field
* *voidfraction* = (optional, default "voidfraction") name of the finite volume void fraction field
* *molarConc* = (optional, default "molarConc") name of the finite volume molar concentration field
* *partTemp* = (optional, default "partTemp") name of the finite volume cell averaged particle temperature field
* *partRho* = (optional, default "partRho") name of the finite volume cell averaged density temperature field
* *switch1* = (optional, default false) flag to output verbose information
* *number1* = (optional, default 1) number to adjust execution interval


Examples
""""""""


.. parsed-literal::

   chemistryModels
   (
       species
   );
   speciesProps
   {
        ChemistryFile     "$casePath/CFD/constant/foam.inp";
        verbose           false;
   }

Description
"""""""""""

The chemistry model performs the calculation of chemical reactional effects
acting on each DEM particle. The species model is the model, where the specified
species fields (from the foam.inp folder) are initialized, and information such
as temperature, density, molar concentration and more importantly the molar
fractions are transferred to DEM side.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`chemistryModel <chemistryModel>`

