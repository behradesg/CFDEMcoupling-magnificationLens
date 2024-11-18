.. index:: momCoupleModel implicitCouple

momCoupleModel implicitCouple command
=====================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   momCoupleModels
   (
       implicitCouple
   );
   implicitCoupleProps
   {
       velFieldName          "U";
       granVelFieldName      "Us";
       voidfractionFieldName "voidfraction";
       KslLimit              scalar1;
       minAlphaP             scalar2;
   }

* *U* = name of the finite volume fluid velocity field
* *Us* = name of the finite volume granular velocity field
* *voidfraction* = name of the finite volume void fraction field
* *scalar1* = (optional, default 1e10) limit implicit momentum exchange field
* *scalar2* = (optional, default SMALL) minimum value for local particle volume fraction to calculate the exchange field


Examples
""""""""


.. parsed-literal::

   momCoupleModels
   (
       implicitCouple
   );
   implicitCoupleProps
   {
       velFieldName          "U";
       granVelFieldName      "Us";
       voidfractionFieldName "voidfraction";
   }

Description
"""""""""""

The *implicitCouple* model is a momCoupleModel model providing an implicit
momentum source term for the CFD solver.

Restrictions
""""""""""""


Only for solvers that include implicit momentum exchange.

Related commands
""""""""""""""""

:doc:`momCoupleModel <momCoupleModel>`

