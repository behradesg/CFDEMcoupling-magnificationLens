.. index:: smoothingModel constDiffAndTemporalSmoothing

smoothingModel constDiffAndTemporalSmoothing command
====================================================

Syntax
""""""

Defined in dictionary depending on the application.


.. parsed-literal::

   smoothingModel constDiffAndTemporalSmoothing;
   constDiffAndTemporalSmoothingProps
   {
       lowerLimit                    number1;
       upperLimit                    number2;
       smoothingLength               lengthScale;
       smoothingLengthReferenceField lengthScaleRefField;
       smoothingStrength             smoothingStrength;
       correctBoundary               switch1;
       verbose;
   }

* *number1* = scalar fields will be bound to this lower value
* *number2* = scalar fields will be bound to this upper value
* *lengthScale* = length scale over which the exchange fields will be smoothed out
* *lengthScaleRefField* = length scale over which reference fields (e.g., the average particle velocity) will be smoothed out. Should be always larger than lengthScale. If not specified, will be equal to lengthScale.
* *smoothingStrength* = control parameter gamma for the smoothing, lower value yields stronger smoothing (gamma = 1 results in an equal contribution from the un-smoothed and smoothed fields)
* *correctBoundary* = (optional, default false) activate to use purely temporal smoothing on the boundary field, avoids interpolation errors near the domain boundary
* *verbose* = (optional, default false) flag for debugging output


Examples
""""""""


.. parsed-literal::

   constDiffAndTemporalSmoothingProps
   {
       lowerLimit       0.1;
       upperLimit       1e10;
       smoothingLength  1500e-6;
       smoothingLengthReferenceField 9000e-6;
       referenceField   "p";
       gamma            1.0;
   }

Description
"""""""""""

The *constDiffAndTemporalSmoothing* model is a smoothing model that combines the
spacial smoothing of :doc:`constDiffSmoothing <smoothingModel_constDiffSmoothing>` and
the temporal smoothing of :doc:`temporalSmoothing <smoothingModel_temporalSmoothing>` for
the relaxation of a desired quantity. This model can be used to filter out
high-frequency fluctuations (e.g. numerical noise) controlled via the smoothing length
and the temporal smoothing strength parameter gamma.

For more details, see :ref:`Vångö et al. (2018) <Vångö2018>` and :ref:`Nijssen et al. (2020) <Nijssen2020>`.

.. _Vångö2018:



**(Vångö2018)** M. Vångö, S. Pirker, T. Lichtenegger. (2018):
"Unresolved CFD-DEM modeling of multiphase flow in densely packed particle beds",
Applied Mathematical Modelling

.. _Nijssen2020:



**(Nijssen2020)** T.M.J. Nijssen, J.A.M. Kuipers, J. van der Stel, A.T. Adema, K.A. Buist. (2020):
"Complete liquid-solid momentum coupling for unresolved CFD-DEM simulations",
International Journal of Multiphase Flow

Restrictions
""""""""""""


This model is tested in a limited number of flow situations.

Related commands
""""""""""""""""

:doc:`smoothingModel <smoothingModel>`
:doc:`constDiffSmoothing <smoothingModel_constDiffSmoothing>`
:doc:`temporalSmoothing <smoothingModel_temporalSmoothing>`

