.. index:: smoothingModel temporalSmoothing

smoothingModel temporalSmoothing command
========================================

Syntax
""""""

Defined in dictionary depending on the application.


.. parsed-literal::

   smoothingModel temporalSmoothing;
   temporalSmoothingProps
   {
       lowerLimit number1;
       upperLimit number2;
       refField   referenceField;
       gamma      smoothingStrength;
   }

* *number1* = scalar fields will be bound to this lower value
* *number2* = scalar fields will be bound to this upper value
* *referenceField* = reference to the un-smoothed field required for the relaxation operation
* *smoothingStrength* = control parameter for the smoothing, lower value yields stronger smoothing (gamma = 1 results in an equal contribution from the un-smoothed and smoothed fields)


Examples
""""""""


.. parsed-literal::

   temporalSmoothingProps
   {
       lowerLimit     0.1;
       upperLimit     1e10;
       referenceField "p";
       gamma          1.0;
   }

Description
"""""""""""

The *temporalSmoothing* model is a smoothing model that utilizes temporal
relaxation of a desired quantity. This model can be used to filter out
high-frequency fluctuations (e.g. numerical noise) controlled via the control
parameter gamma.
Note that this model does NOT smooth the calculated fields, instead smoothing is
performed on a separate (smooth) field which uses the calculated (un-smooth)
field as a reference.
Thus its usage is limited and CANNOT be used to smooth the exchange fields
similar to other smoothing models.
For further information see Vångö et al., "Unresolved CFD-DEM modeling of
multiphase flow in densely packed particle beds", Appl. Math. Model. (2018).

Restrictions
""""""""""""


This model does NOT smooth the calculated fields and can therefore NOT be used
as a general smoothing model to smoothen the exchange fields.
Attempting this will generate an error.

Related commands
""""""""""""""""

:doc:`smoothingModel <smoothingModel>`

