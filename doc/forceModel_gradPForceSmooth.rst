.. index:: forceModel gradPForceSmooth

forceModel gradPForceSmooth command
===================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       gradPForceSmooth;
   );
   gradPForceSmoothProps
   {
       pFieldName         "pressure";
       velocityFieldName  "U";
       useAddedMass       scalar1;
       treatForceExplicit switch1;
       treatForceDEM      switch2;
       interpolation      switch3;
       smoothingModel     "smoothingModel";
   }

* *pressure* = name of the finite volume fluid pressure field
* *U* = name of the finite volume fluid velocity field
* *scalar1* = (optional, default 0) coefficient of added mass accounted for
* *switch1* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch2* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch3* = (optional, default false) flag to use interpolated pressure values
* *smoothingModel* = name of smoothing model


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       gradPForceSmooth;
   );
   gradPForceSmoothProps
   {
       pFieldName        "p_rgh";
       velocityFieldName "U";
       interpolation     false;
       smoothingModel    "temporalSmoothing";
       temporalSmoothingProps
       {
           lowerLimit 0.1;
           upperLimit 1e10;
           refField   "p_rgh";
           gamma      1.0;
       }

   }

Description
"""""""""""

The *gradPForceSmooth* model calculates the particle based pressure gradient
force identically to the :doc:`gradPForce <forceModel_gradPForce>` model but
allows smoothing of the pressure prior to the force calculation (without
altering the original pressure field).
Any smoothing model can be used and does not have to be the same as specified in
couplingProperties. Properties for the smoothing model have to be specified in a
sub-dictionary within *gradPForceSmoothProps*\ .

Restrictions
""""""""""""


A volScalarField "pSmooth" MUST be specified in the initial time directory!

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`, :doc:`gradPForce <forceModel_gradPForce>`

