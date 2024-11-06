.. index:: voidFractionModel Gauss

voidFractionModel Gauss command
===============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   voidFractionModel Gauss;
   GaussProps
   {
       maxCellsPerParticle number1;
       alphaMin            number2;
       weight              number3;
       porosity            number4;
   }

* *number1* = maximum number of cells covered by a particle (search will fail when more than *number1* cells are covered by the particle)
* *number2* = minimum limit for void fraction
* *number3* = (optional, default 1.0) scaling of the particle volume to account for porosity or agglomerations.
* *number4* = (optional, default 1.0) diameter of the particle's representation is artificially increased according to *number2* \* Vparticle, volume remains unaltered!


Examples
""""""""


.. parsed-literal::

   voidFractionModel Gauss;
   GaussProps
   {
       maxCellsPerParticle 1000;
       alphaMin            0.10;
       weight              1.0;
       porosity            1.0;
   }

Description
"""""""""""

The *Gauss* void fraction model is supposed to be used when a particle (or its
representation) is bigger than a CFD cell. The void fraction field is set in
those cell whose centres are inside the particle. The volume is here distributed
according to a Gaussian distribution.

The region of influence of a particle can be increased artificially by
"porosity", which  blows up the particles, but keeps their volume (for
void fraction calculation) constant.

The particle volume occupied in the CFD domain can be adjusted by the parameter
"weight", using Vparticle=dsphere\^3\*pi/6\*weight.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`voidFractionModel <voidFractionModel>`,
:doc:`bigParticle <voidFractionModel_bigParticleVoidFraction>`

