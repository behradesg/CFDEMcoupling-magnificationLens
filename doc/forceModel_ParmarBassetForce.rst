.. index:: forceModel ParmarBassetForce

forceModel ParmarBassetForce command
====================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       ParmarBassetForce
   );
   ParmarBassetForceProps
   {
       velFieldName        "U";
       UsFieldName         "Us";
       nIntegral           scalar1;
       discretisationOrder scalar2;
       treatForceExplicit  switch1;
       verbose             switch2;
       interpolation       switch3;
       smoothingModel      "smoothingModel";
   }

* *U* = name of the finite volume fluid velocity field
* *Us* = name of the finite volume cell averaged particle velocity field
* *scalar1* = number of timesteps considered in the near history (integer > 1)
  *scalar2* = (optional, default 1) discretisation order of the far history differential equations (1 or 2)
* *switch1* = (optional, default true) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch2* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch3* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *smoothingModel* = name of smoothing model for the dUrel/dt field


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       ParmarBassetForce
   );
   ParmarBassetForceProps
   {
       velFieldName        "U";
       USFieldName         "Us"
       nIntegral           10;
       discretisationOrder 1;
       smoothingModel      constDiffAndTemporalSmoothing;
       constDiffAndTemporalSmoothingProps
       {
           lowerLimit          1e-8;
           upperLimit          1e8;
           smoothingLength     0.1;
           smoothingStrength   0.001;
           correctBoundary     true;
       }
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *ParmarBassetForce* model
calculates the Basset history force for each particle, based on the method by
:ref:`Parmar et al. (2018) <Parmar2018>`.

For more detail, see :ref:`Nijssen et al. (2020) <Nijssen2020>`.

.. _Parmar2018:



**(Parmar2018)** M. Parmar, S. Annamalai, S. Balachandar, A. Prosperetti. (2018):
"Differential Formulation of the Viscous History Force on a Particle for Efficient and Accurate Computation",
Journal of Fluid Mechanics

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

