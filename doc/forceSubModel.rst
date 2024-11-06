.. index:: forceSubModels

forceSubModels command
======================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
sub-dictionary of the force model in use. If no force sub-model is applied, ImEx
is used as default. If the keyword "forceSubModels" is provided, a choice of
sub-model is demanded.


.. parsed-literal::

   forceSubModels
   (
       model_x
       model_y
   );

* model = name of force sub-model to be applied

Examples
""""""""


.. parsed-literal::

   forceSubModels
   (
       ImEx
   );

.. note::

   This examples list might not be complete - please look for other models
   (forceSubModel XY) in this documentation.

Description
"""""""""""

The force sub model is designed to hold the settings a force model can have.
Depending on the availability within the respective force model, the following
options are handled:

* *treatForceExplicit* - switch for the purely explicit consideration of the force
  term in the equation of motion on the CFD side (off -> the force is considered
  semi-implicitly; default off)
* *treatForceDEM* - switch for the consideration of the forces on the DEM side only
  (off -> calculate forces for DEM and CFD; default off)
* *implForceDEM* - If true, the fluid velocity and drag coefficient are communicated
  to the DEM calculation at each coupling time step and the drag force is
  calculated at each DEM time step, using the current particle velocity.
  If false, a force term is communicated to the DEM calculation at each coupling
  time step, the term is constant for one coupling interval.
  (on -> DEM forces are updated every DEM step; default off)
* *verbose* - switch for debug output to screen (on -> enable debug output; default
  off)
* *interpolation* - switch for the usage of interpolation models when getting data
  for the Lagrangian calculation from Eulerian fields;
  f false, the cell centre values are used. (default off)
* *useFilteredDragModel* - switch for using a coarse-grid version of the Beetstra
  drag model (takes grid-size effects into account; default = off)
* *useParcelSizeDependentFilteredDrag* - switch for using a coarse-grid version of
  the Beetstra drag model (takes parcel-size effects into account, will force the
  switch useFilteredDragModel to "on"; default = off)
* *implForceDEMaccumulated* - Can only be used in combination with implForceDEM
  switch, drag force values of each DEM time step are accumulated and passed on to
  the CFD-calculation. (default off)
* *scalarViscosity* - switch for the usage of a user-defined viscosity nu for the
  calculation of the drag force; The CFD calculation always uses the value of the
  transport model. (off -> use transportProperties nu; default off)


Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`ImEx <forceSubModel_ImEx>`

Default
"""""""

none

