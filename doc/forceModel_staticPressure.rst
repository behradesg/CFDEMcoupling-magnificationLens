.. index:: forceModel staticPressure

forceModel staticPressure command
=================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
      staticPressure
   );
   staticPressureProps
   {
      rhoGas number1; 
      voidfractionFieldName "voidfraction";
      rhoPart number2; 
      DomainSolidVolumeFraction number3; 
      g_DEM gravityVector; 
   }

* *number1* = density of the gas phase
* *voidfraction* = name of the finite volume void fraction field
* *number2* = density of the particles
* *number3* = domain-average particle volume fraction (mass loading)
* *gravityVector* = gravity vector


Examples
""""""""


.. parsed-literal::

   forceModels
   (
      staticPressure
   );
   staticPressureProps
   {
      rhoGas 1.2; 
      voidfractionFieldName "voidfraction";
      rhoPart 1500; 
      DomainSolidVolumeFraction 0.05; 
      g_DEM (0 0 -9.81); 
   }

Description
"""""""""""

As discussed in :doc:`gravityEff <otherForceModel_gravityEff>`, in case of
simulating periodic boxes, it is necessary to have a gravitational source term.
Since that force is added to the gas momentum equation, we need to add the same
force excluding the effect of the gravitational force on the particles
(the gravitational force on the particles is already available on the LIGGGHTS side)
to drive the particles.
This force model performs the calculation of the following force acting on each
DEM particle,

.. image:: Eqs/forceModels_staticPressure_pic1.jpg
   :align: center

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

