.. index:: energyModel wallHeatTransferYagi

energyModel wallHeatTransferYagi command
========================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   energyModels
   (
       wallHeatTransferYagi
   );
   wallHeatTransferYagiProps
   {
       QWallFluidName         "QWallFluid";
       QWallFluidCoeffNAme    "QWallFluidCoeff";
       wallTempName           "wallTemp";
       tempFieldName          "T";
       voidfractionFieldName  "voidfraction";
       voidfractionMax        scalar1;
       maxSource              scalar2;
       velFieldName           "U";
       densityFieldName       "rho";
       implicit               switch1;
       verbose                switch2;
   }

* *QWallFluid* = name of the wall-fluid heat transfer rate field
* *QwallFluidCoeff* = name of the wall-fluid heat transfer coefficient field
* *wallTemp* = name of the wall temperature field
* *T* = name of the fluid temperature field
* *voidfraction* = name of the finite volume void fraction field
* *scalar1* = maximum void fraction for a cell to be considered packed
* *scalar2* = (optional, default 1e30) maximum allowed source term
* *U* = name of the finite volume fluid velocity field
* *rho* = name of the fluid density field
* *switch1* = (optional, default true) activate to treat the fluid temperature implicitly
* *switch2* = (optional, default false) activate to write additional fields, and write cell-based data to the terminal


Examples
""""""""


.. parsed-literal::

   energyModels
   (
       wallHeatTransferYagi
   );
   wallHeatTransferYagiProps
   {
       QWallFluidName         "QWallFluid";
       QWallFluidCoeffNAme    "QWallFluidCoeff";
       wallTempName           "wallTemp";
       tempFieldName          "T";
       voidfractionFieldName  "voidfraction";
       voidfractionMax        0.5;
       velFieldName           "U";
       densityFieldName       "rho";
       implicit               true;
   }

Description
"""""""""""

The energy model performs calculation of wall-to-bed heat transfer for a
packed bed, based on the correlation of :ref:`Yagi and Wakao (1959) <Yagi1959>`.

.. _Yagi1959:



**(Yagi1959)** S. Yagi, N. Wakao. (1959):
"Heat and Mass Transfer from Wall to Fluid in Packed Beds",
AIChE Journal

Restrictions
""""""""""""


.. warning::

   Model not validated!

Related commands
""""""""""""""""

energyModel

