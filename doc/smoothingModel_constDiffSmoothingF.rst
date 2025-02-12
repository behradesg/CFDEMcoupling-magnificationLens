.. index:: smoothingModel constDiffSmoothingF

smoothingModel constDiffSmoothingF command
=========================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   smoothingModel constDiffSmoothingF;
   constDiffSmoothingProps
   {
       lowerLimit                        number1;
       upperLimit                        number2;
       filterLength                      filterScale;
       smoothingLengthReference          filterScaleRef;
       smoothingLengthFieldName          fieldName1;
       smoothingLengthReferenceFieldName fieldName2;
       verbose;
   }

* *number1* = scalar fields will be bound to this lower value
* *number2* = scalar fields will be bound to this upper value
* *filterScale* = filter length over which the exchange fields will be smoothed out
* *filterScaleRef* = (optional) length scale over which reference fields (e.g., the average particle velocity) will be smoothed out. Should be always larger than lengthScale. If not specified, will be equal to lengthScale.
* *fieldName1* = (optional) name of scalar field to be used as local smoothing length.
* *fieldName2* = (optional) name of scalar field to be used as local smoothing length for reference fields.
* *verbose* = (optional, default false) flag for debugging output


Examples
""""""""


.. parsed-literal::


   constDiffSmoothingFProps
   {
     lowerLimit 0.01;
     upperLimit 1.0;
     filterLength 0.0015;
   }

Description
"""""""""""

The *constDiffSmoothingF* model is a basic smoothingModel model which reads a
filter length scale being used for smoothing the exchange fields
(void fraction, Ksl, Us, and f if present). This model can be used for smoothing explicit
force coupling fields, as well as implicit force coupling algorithms.
A transient diffusion equation is solved which reads as,

.. image:: Eqs/smoothingModel_constDiffSmoothingF_diffEq.jpg
   :align: center

The diffusion coefficient in *constDiffSmoothing* is evaluated using,

.. image:: Eqs/smoothingModel_constDiffSmoothingF_oldDiff.jpg
   :align: center

However, in this model the diffusion coeefiecient is calacualte using,

.. image:: Eqs/smoothingModel_constDiffSmoothingF_newDiff.jpg
   :align: center

Since smoothing using the transient diffusion equation is equivalent to
smoothing by the Gaussian kernel with standard deviation of \sigma = \sqrt(2*D), we 
can show that smoothing using *constDiffSmoothingF* model is less diffusive than 
*constDiffSmoothing* model with using similiar filter and smoothing lengths.

.. image:: Eqs/smoothingModel_constDiffSmoothingF_kernelComparison.jpg
   :align: center

Restrictions
""""""""""""

.. warning::

   The fields "f" and "fSmooth" must be placed in the initial
   time directory! This is because zeroGradient boundary conditions for the fields
   "f" and "fSmooth" must be specified, otherwise the smoothing operation will give
   an error.

Related commands
""""""""""""""""

:doc:`smoothingModel <smoothingModel>`

