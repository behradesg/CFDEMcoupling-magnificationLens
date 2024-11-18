.. index:: voidFractionModel IB

voidFractionModel IB command
============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   voidFractionModel IB;
   IBProps
   {
       maxCellsPerParticle number1;
       alphaMin            number2;
       scaleUpVol          number3;
   }

* *number1* = maximum number of cells covered by a particle (search will fail when
  more than *number1* cells are covered by the particle)
* *number2* = minimum limit for void fraction
* *number3* = diameter of the particle's representation is artificially increased
  according to *number3* \* Vparticle, volume remains unaltered!


Examples
""""""""


.. parsed-literal::

   voidFractionModel IB;
   IBProps
   {
       maxCellsPerParticle 1000;
       alphaMin            0.10;
       scaleUpVol          5.0;
   }

Description
"""""""""""

The *IB* void fraction model is supposed to be used when a particle (or its
representation) is bigger than a CFD cell. The void fraction field is set in
those cell whose centres are inside the particle. The model is specially
designed for cfdemSolverIB and creates a smooth transition of the void fraction
at the particle surface. Cells which are only partially covered by solid are
marked by void fraction values between 0 and 1 respectively.

The region of influence of a particle can be increased artificially by
"scaleUpVol", which blows up the particles, but keeps their volume (for
void fraction calculation) constant.

Code of this sub-model was contributed by Alice Hager, JKU.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`voidFractionModel <voidFractionModel>`

