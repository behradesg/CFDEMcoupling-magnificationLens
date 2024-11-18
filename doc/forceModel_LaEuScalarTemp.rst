.. index:: forceModel LaEuScalarTemp

forceModel LaEuScalarTemp command
=================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       LaEuScalarTemp
   );
   LaEuScalarTempProps
   {
       velFieldName          "U";
       tempFieldName         "T";
       voidfractionFieldName "voidfraction";
       partTempName          "Temp";
       partHeatFluxName      "convectiveHeatFlux";
       lambda                scalar1;
       Cp                    scalar2;
       maxSource             scalar3;
       verbose               switch1;
       interpolation         switch2;
       scalarViscosity       switch3;
   }

* *U* = name of the finite volume fluid velocity field
* *T* = name of the finite volume scalar temperature field
* *voidfraction* = name of the finite volume void fraction field
* *Temp* = name of the DEM data representing the particles temperature
* *convectiveHeatFlux* = name of the DEM data representing the particle-fluid convective heat flux
* *scalar1* = fluid thermal conductivity [W/(m\*K)]
* *scalar2* = fluid specific heat capacity [W\*s/(kg\*K)]
* *scalar3* = (optional, default 1e30) limit maximal turbulence
* *switch1* = (optional, default false) for verbose run
* *switch2* = (optional, default false) flag to use interpolated void fraction and fluid velocity values
* *switch3* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       LaEuScalarTemp
   );
   LaEuScalarTempProps
   {
       velFieldName          "U";
       tempFieldName         "T";
       voidfractionFieldName "voidfraction";
       partTempName          "Temp";
       partHeatFluxName      "convectiveHeatFlux";
       lambda                0.0256;
       Cp                    1007;
   }

Description
"""""""""""

This "force model" does not influence the particles or the fluid flow! Using the
particles' temperature a scalar field representing "particle-fluid heat flux" is
calculated. The solver then uses this source field in the scalar transport
equation for the temperature. The model for convective heat transfer is based on
Li and Mason (2000), A computational investigation of transient heat transfer in
pneumatic transport of granular particles, Pow.Tech 112

Restrictions
""""""""""""


Goes only with cfdemSolverPisoScalar. The force model has to be the second (!!!)
model in the forces list.

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

