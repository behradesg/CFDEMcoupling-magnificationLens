.. index:: forceModel particleVelocityController 

forceModel particleVelocityController  command
================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       particleVelocityController
   );
   particleVelocityControllerProps
   {
   
     controllerCellSetNames ( cellSet names );
     controllVelocity controllVelocitySwitch;
     rhoPart rhoPValue;
     interpolation intSwitch;
     controllerErrorSwitch contErrSwitch;
     treatForceDem forceDEMSwitch;
   }

* *cellSet names* = name of the controller cellsets
* *controllVelocitySwitch* = it switches the controller on/off using true/false
* *intSwitch* = interpolation switch (false/true)
* *rhoPValue* = particle density
* *contErrSwitch* = velocity controller error per particle print (true/false)
* *forceDEMSwitch* = switch to consider the force in the DEM side only (should always set to true)


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       particleVelocityController
   );
   particleVelocityControllerProps
   {
      controllerCellSetNames ( topControllerCellSet 
  		               bottomControllerCellSet      				
       	             );
      controllVelocity true;
      rhoPart 1500;
      interpolation true;
      controllerErrorSwitch false;
      treatForceDem true;
   }

Description
"""""""""""

This force model applies a force based on the relative velocity between the discrete and 
continuum particle phase velocities on each particle in the controller cellset to push 
the velocity of discrete particles to the one from continuum particle phase. Refer to
:ref:`Esgandari et al. (2024) <Esgandari2024>` for more information.

Restrictions
""""""""""""
This model requires U.particles from magnification solver and the cellsets should be defined using topoSet 
command and stored in "constant/polyMesh/sets".

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`


----------


.. _Esgandari2024:



**(Esgandari, 2024)** 
Esgandari, Behrad, Daniel Queteschiner, Stefan Pirker, and Simon Schneiderbauer. 
"Discrete magnification lens model: A new hybrid multi-scale modelling method for fluid-particle systems." 
Powder Technology 445 (2024): 120094.

