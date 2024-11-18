.. index:: voidFractionModel centre

voidFractionModel centre command
================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   voidFractionModel centre;
   centreProps
   {
       alphaMin number1;
       weight   number2;
   }

* *number1* = minimum limit for void fraction
* *number2* = (optional) scaling of the particle volume to account for porosity or agglomerations.


Examples
""""""""


.. parsed-literal::

   voidFractionModel centre;
   centreProps
   {
       alphaMin 0.1;
       weight   1.0;
   }

Description
"""""""""""

The *centre* void fraction model calculates the void fraction in a CFD cell
accounting for the volume of the particles whose centres are inside the cell.

The particle volume occupied in the CFD domain can be adjusted by the parameter
"weight", using Vparticle=dsphere\^3\*pi/6\*weight.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`voidFractionModel <voidFractionModel>`

