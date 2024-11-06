.. index:: smoothingModel constDiffSmoothing

smoothingModel constDiffSmoothing command
=========================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   smoothingModel constDiffSmoothing;
   constDiffSmoothingProps
   {
       lowerLimit                        number1;
       upperLimit                        number2;
       smoothingLength                   lengthScale;
       smoothingLengthReference          lengthScaleRef;
       smoothingLengthFieldName          fieldName1;
       smoothingLengthReferenceFieldName fieldName2;
       verbose;
   }

* *number1* = scalar fields will be bound to this lower value
* *number2* = scalar fields will be bound to this upper value
* *lengthScale* = length scale over which the exchange fields will be smoothed out
* *lengthScaleRef* = (optional) length scale over which reference fields (e.g., the average particle velocity) will be smoothed out. Should be always larger than lengthScale. If not specified, will be equal to lengthScale.
* *fieldName1* = (optional) name of scalar field to be used as local smoothing length.
* *fieldName2* = (optional) name of scalar field to be used as local smoothing length for reference fields.
* *verbose* = (optional, default false) flag for debugging output


Examples
""""""""


.. parsed-literal::

   constDiffSmoothingProps
   {
       lowerLimit                    0.1;
       upperLimit                    1e10;
       smoothingLength               1500e-6;
       smoothingLengthReferenceField 9000e-6;
   }

Description
"""""""""""

The *constDiffSmoothing* model is a basic smoothingModel model which reads a
smoothing length scale being used for smoothing the exchange fields
(void fraction, Ksl, f if present). This model can be used for smoothing explicit
force coupling fields, as well as implicit force coupling algorithms.
Smoothing for reference fields is performed to "fill in" values in cells in
which these reference fields are not specified. Values calculated in the cells
(via Lagrangian-To-Euler mapping) are NOT changed! These reference fields are,
e.g. the average particle velocity, which are not specified in all cells in case
the flow is rather dilute.

Alternative to *smoothingLength* and *smoothingLengthReference*\ , 
*smoothingLengthFieldName* and/or *smoothingLengthReferenceFieldName* can be used
to define spatial variation of the smoothing lengths. Either the scalar or field 
options must be used, giving both will result in errors.

Restrictions
""""""""""""


This model is tested in a limited number of flow situations.

.. warning::

   In case a smoothing model is used in conjunction with
   "PimpleImEx" solvers, the fields "f" and "fSmooth" must be placed in the initial
   time directory! This is because zeroGradient boundary conditions for the fields
   "f" and "fSmooth" must be specified, otherwise the smoothing operation will give
   an error.

Related commands
""""""""""""""""

:doc:`smoothingModel <smoothingModel>`

