.. index:: forceModel ShirgaonkarIB

forceModel ShirgaonkarIB command
================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       ShirgaonkarIB
   );
   ShirgaonkarIBProps
   {
       velFieldName      "U";
       pressureFieldName "pressure";
       twoDimensional;
       useTorque;
       treatForceExplicit switch1;
   }

* *U* = name of the finite volume fluid velocity field
* *pressure* = name of the finite volume pressure field
* *twoDimensional* = optional keyword for conducting a two dimensional calculation
* *useTorque* =  optional keyword for calculating particle torque
* *switch1* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       ShirgaonkarIB
   );
   ShirgaonkarIBProps
   {
       velFieldName "U";
       pressureFieldName "p";
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *ShirgaonkarIB* model
calculates the drag force (viscous and pressure force) acting on each particle
in a resolved manner (see :ref:`Shirgaonkar et al. (2009) <Shirgaonkar2009>`).
This model is only suited for resolved CFD-DEM simulations where
the particle is represented by immersed boundary method.

Restrictions
""""""""""""


Only for immersed boundary solvers.

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`


----------


.. _Shirgaonkar2009:



**(Shirgaonkar, 2009)** Shirgaonkar, A. A., MacIver, M. A. and Patankar, N. A., (2009),
"A new mathematical formulation and fast algorithm for fully resolved simulation
of self-propulsion", J. Comput. Phys., 228, pp. 2366-2390.

