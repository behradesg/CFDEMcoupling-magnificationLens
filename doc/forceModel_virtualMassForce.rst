.. index:: forceModel virtualMassForce

forceModel virtualMassForce command
===================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       virtualMassForce
   );
   virtualMassForceProps
   {
       velFieldName "U";
       voidfractionFieldName "voidfraction";
       UsFieldName "Us";
       phiFieldName "phi";
       splitUrelCalculation switch1;
       useUs switch2;
       useFelderhof switch3;
       Cadd scalar1;
       treatForceExplicit switch4;
       interpolation switch5;
       smoothingModel "smoothingModel";
   }

* *U* = name of the finite volume fluid velocity field
* *voidfraction* = name of the finite volume void fraction field
* *Us* = name of the finite volume cell averaged particle velocity field
* *phi* = name of the finite volume flux field
* *switch1* = (optional, default false) indicator to split calculation of Urel between CFDEM and LIGGGHTS
* *switch2* = (optional, default false) indicator to use the cell-averaged particle velocity Us for calculation of Urel
* *switch3* = (optional, default false) indicator to use the correlation by Felderhof for the virtual mass coefficient
* *scalar1* = (optional, default 0.5) virtual mass coefficient
* *switch4* = (optional, default true) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch5* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *smoothingModel* = name of smoothing model for the DU/Dt field


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       virtualMassForce
   );
   virtualMassForceProps
   {
       velFieldName "U";
       voidfractionFieldName "voidfraction"
       USFieldName "Us"
       phiFieldName "phi";
       smoothingModel off;
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *virtualMassForce* model
calculates the virtual mass force for each particle.

For more detail, see :ref:`Nijssen et al. (2020) <Nijssen2020>`.

.. _Nijssen2020:



**(Nijssen2020)** T.M.J. Nijssen, J.A.M. Kuipers, J. van der Stel, A.T. Adema, K.A. Buist. (2020):
"Complete liquid-solid momentum coupling for unresolved CFD-DEM simulations",
International Journal of Multiphase Flow

Restrictions
""""""""""""


.. warning::

   Model not validated!

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

