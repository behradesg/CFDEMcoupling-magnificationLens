.. index:: voidFractionModel bigParticle

voidFractionModel bigParticle command
=====================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   voidFractionModel bigParticle;
   bigParticleProps
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

   voidFractionModel bigParticle;
   bigParticleProps
   {
       maxCellsPerParticle 1000;
       alphaMin            0.10;
       weight              1.0;
       porosity            5.0;
   }

Description
"""""""""""

The *bigParticle* void fraction model is supposed to be used when a particle (or
its representation) is bigger than a CFD cell. The void fraction field is set in
those cell whose centres are inside the particle which results in a stairstep
representation of the bodies within the mesh (i.e. void fraction is either 1
(fluid) of zero (solid)). For archiving accurate results, approx. 8 cells per
particle diameter are necessary.

The region of influence of a particle can be increased artificially by
"porosity", which  blows up the particles, but keeps their volume (for
void fraction calculation) constant.

The particle volume occupied in the CFD domain can be adjusted by the parameter
"weight", using Vparticle=dsphere\^3\*pi/6\*weight.

Parts of this sub-model were contributed by Alice Hager, JKU.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`voidFractionModel <voidFractionModel>`

