.. index:: smoothingModel

smoothingModel command
======================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   smoothingModel model;

* model = name of the smoothingModel to be applied

Examples
""""""""


.. parsed-literal::

   smoothingModel off;
   smoothingModel constDiffSmoothing;

.. note::

   This examples list might not be complete - please look for other models
   (smoothingModel XY) in this documentation.

.. warning::

   In case a smoothing model is used in conjunction with
   "PimpleImEx" solvers, the fields "f" and "fSmooth" must be placed in the initial
   time directory! This is because zeroGradient boundary conditions for the fields
   "f" and "fSmooth" must be specified, otherwise the smoothing operation will give
   an error.

Description
"""""""""""

The *smoothingModel* is the base class for models that smoothen the exchange
fields (i.e., void fraction and the Ksl field in case of implicit force coupling).
This is relevant in case one uses a small grid resolution compared to the local
particle diameter (or parcel diameter in case one uses a parcel approach).

Restrictions
""""""""""""


These models are in beta testing.

Default
"""""""

none

