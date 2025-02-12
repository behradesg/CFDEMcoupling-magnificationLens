.. index:: smoothingModel laplaceFilterSmoothing

smoothingModel laplaceFilterSmoothing command
=========================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   smoothingModel laplaceFilterSmoothing;
   laplaceFilterSmoothingProps
   {
     upperLimit                          number1;
     lowerLimit                          number2;
     iterations                          number3;
     widthCoeff                          number4;
     verbose                             bool;
   }

* *number1* = scalar fields will be bound to this upper value
* *number2* = scalar fields will be bound to this lower value
* *number3* = number of iterations for filtering with default value of 1
* *number4* = the width coefficient with the default value of 6
* *verbose* = (optional, default false) flag for debugging output


Examples
""""""""


.. parsed-literal::


  laplaceFilterSmoothingProps
  {
     upperLimit                          1.0e4;
     lowerLimit                          1.0e-4;
     iterations                          1;
     widthCoeff                          24.0;
     verbose                             false;
  }

Description
"""""""""""

This smoothing model uses the laplace filter implementation in OpenFOAM. It 
solves the following equation to smooth the field \phi,

.. image:: Eqs/smoothingModel_laplaceFilterSmoothing_Eq.jpg
   :align: center

where coeff = \Delta_x^2/C and \Delta_x is the grid size and C is the *widthCoeff*. 
If *widthCoeff* = 24, the laplace filter is equal to second-order approximation of 
the three-dimensional Gaussian filter. In case of *widthCoeff* = 6, the smoothed field
will be the arithmatic average of the surrounding cells.

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

