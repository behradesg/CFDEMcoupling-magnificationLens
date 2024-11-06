.. index:: chemistryModel reactantPerParticle

chemistryModel reactantPerParticle command
==========================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   chemistryModels
   (
       reactantPerParticle
   );
   reactantPerParticleProps
   {
       voidfractionFieldName   "voidfraction";
       Nevery                  number1;
   }

* *voidfraction* = (optional, default "voidfraction") name of the finite volume void fraction field
* *number1* = (optional, default 1) number to adjust execution interval


Examples
""""""""


.. parsed-literal::

   chemistryModels
   (
       reactantPerParticle
   );
   reactantPerParticleProps
   {
       voidfractionFieldName   "voidfraction";
       Nevery                  1;
   }

Description
"""""""""""

The chemistry model performs the calculation of chemical reactional effects
acting on each DEM particle. The reactantPerParticle model is the model to
communicate the available reactant per particle.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`chemistryModel <chemistryModel>`

