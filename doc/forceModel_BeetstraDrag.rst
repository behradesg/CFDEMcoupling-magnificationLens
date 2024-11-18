.. index:: forceModel BeetstraDrag 

forceModel BeetstraDrag  command
================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       BeetstraDrag
   );
   BeetstraDragProps
   {
       velFieldName          "U";
       voidfractionFieldName "voidfraction";
       minVoidfraction       scalar1;
       granVelFieldName      "Us";
       useFilteredDragModel;
       g                     gravity;
       dPrim                 dPrimValue;
       rhoP                  rhoPValue;
       rho                   rhoValue;
       nuf                   nufValue;
       useParcelSizeDependentFilteredDrag;
       k                     kValue;
       treatForceExplicit;
       implForceDEM;
       verbose;
       interpolation;
   }

* *U* = name of the finite volume fluid velocity field
* *voidfraction* = name of the finite volume void fraction field
* *minVoidfraction* = minimum void fraction value to ensure meaningful interpolated void fraction (default = 0.1)
* *Us* = name of the finite volume cell averaged particle velocity field
* *useFilteredDragModel* = switch for using a coarsening correction for the Beetstra drag model (takes grid-size effects into account; default = off)
* *gravity* = gravity value (default = 9.81)
* *dPrimValue* = diameter of primary particle
* *rhoPValue* = particle density
* *rhoValue* = finite volume density
* *nufValue* = kinematic viscosity
* *useParcelSizeDependentFilteredDrag* = switch for using a coarsening correction for the Beetstra drag model (only used if *useFilteredDragModel* is on; default = off)
* *kValue*  = factor for parcels size effect (default = 0.05; must be defined if useParcelSizeDependentFilteredDrag is used)
* *interpolation* = flag to use interpolated void fraction and fluid velocity values (normally off)
* *treatForceExplicit* = switch to force explicit treatment of force (normally off)
* *implForceDEM* = flag to use implicit formulation of drag on DEM side (normally off, if on, this switch will force *treatForceExplicit* to be off)
* *verbose* = switch to force display of data on screen (default: off; typically used for debug purposes)


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       BeetstraDrag
   );
   BeetstraDragProps
   {
       velFieldName          "U";
       voidfractionFieldName "voidfraction";
       granVelFieldName      "Us";
       interpolation true;
       useFilteredDragModel;
       g       9.81;
       dPrim   100e-6;
       rhoP    7000.;
       rho     10.;
       nuf     1.5e-4;
       useParcelSizeDependentFilteredDrag;
       k       0.05;
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *BeetstraDrag* model is a
model that calculates the particle based drag force following the correlation of
:ref:`Beetstra et al. (2007) <Beetstra2007>`.
The filtered drag model is based on :ref:`Radl and Sundaresan (2014) <Radl2014>`.

Restrictions
""""""""""""


This model is strictly valid only for monodisperse gas-particle flows.
For the polydisperse model of :ref:`Beetstra et al. (2007) <Beetstra2007>` use
*BeetstraDragPoly*\ .

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`, BeetstraDragPoly


----------


.. _Beetstra2007:



**(Beetstra, 2007)** 
Beetstra, R., van der Hoef, M. A. and Kuipers J. A. M.,
"Drag force of intermediate Reynolds number flow past mono- and bidisperse arrays of spheres",
AIChE J., 53(2) (2007)

.. _Radl2014:



**(Radl, 2014)** Radl, S. and Sundaresan, S.,
"A drag model for filtered Euler-Lagrange simulations of clustered gas-particle suspensions",
Chem. Eng. Sci., 117, pp. 416-425 (2014)

