.. index:: forceModel interface

forceModel interface command
============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       interface
   );
   interfaceProps
   {
       VOFvoidfractionFieldName "alpha";
       gradAlphaName            "gradAlpha";
       alphaThreshold           scalar1;
       sigma                    scalar2;
       theta                    scalar3;
       deltaAlphaIn             scalar4;
       deltaAlphaOut            scalar5;
       C                        scalar6;
       treatForceExplicit       switch1;
   }

* *alpha* = name of the finite volume fluid volume fraction field in a VOF simulation
* *gradAlpha* = name of gradient fluid volume fraction field
* *scalar1* = parameter used to define the distance of influence of the model
* *scalar2* = fluid gas surface tension
* *scalar3* = Three-phase contact angle for interface force
* *scalar4* = delta value subtracted from alphaThreshold
* *scalar5* = delta value added to alphaThreshold
* *scalar6* = (optional, default 1.0) factor to scale interfacial force
* *switch1* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       interface
   );
   interfaceProps
   {
       VOFvoidfractionFieldName "alpha";
       gradAlphaName            "gradAlpha";
       alphaThreshold           0.55;
       sigma                    0.07;
       theta                    1.12;
       deltaAlphaIn             0.05;
       deltaAlphaOut            0.05;
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *interface* model is a
model that calculates the particle-fluid-gas interfacial force.
(see :ref:`Wierink et al. (2011) <Wierink2011>`)

Restrictions
""""""""""""


Only for VOF simulations.

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`


----------


.. _Wierink2011:



**(Wierink 2011)**
"Mechanistic modelling of particle interface interaction in three phase flows",
Wierink G., Goniva C., Niceno B., Heiskanen K.,
Proc. of the 8th Int. Conf. on CFD in Oil and Gas, Metallurgical and Process Industries,
Trondheim, Norway.

