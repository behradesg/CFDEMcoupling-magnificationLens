.. index:: forceModel TangDrag

forceModel TangDrag  command
============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>` dictionary.

.. code::

   forceModels
   (
       TangDrag
   );

   TangDragProps
   {
       velFieldName            word;
       voidfractionFieldName   word;
       granVelFieldName        word;
       minVoidfraction         scalar;
       scale                   scalar;
       scaleDrag               scalar;
       treatForceExplicit      switch;
       implForceDEM            switch;
       verbose                 switch;
       interpolation           switch;
       scalarViscosity         switch;
   }

* **velFieldName** -- name of the finite volume fluid velocity field
* **voidfractionFieldName** -- name of the finite volume void fraction field
* **granVelFieldName** -- name of the finite volume cell averaged particle
  velocity field
* **minVoidfraction** -- lower void fraction limit (optional, default: :code:`0.1`)
* **scale** -- scaling of particle diameter: d\ :sub:`sim` = scale * d\ :sub:`real`,
  where d\ :sub:`sim` is the particle diameter in the simulation. d\ :sub:`real`
  is the particle diameter as it is measured. Overrides any coarse-graining
  factor used in the DEM setup (optional, default: the coarse-graining factor of
  the DEM setup)
* **scaleDrag** -- scaling factor which directly scales the drag force (optional, default: :code:`1.0`)
* **treatForceExplicit** -- see :doc:`forceSubModels <forceSubModel>`
* **implForceDEM** --see :doc:`forceSubModels <forceSubModel>`
* **verbose** -- see :doc:`forceSubModels <forceSubModel>`
* **interpolation** -- see :doc:`forceSubModels <forceSubModel>`
* **scalarViscosity** -- see :doc:`forceSubModels <forceSubModel>`


Examples
""""""""

.. code::

   forceModels
   (
       TangDrag
   );
   TangDragProps
   {
       velFieldName            "U";
       voidfractionFieldName   "voidfraction";
       granVelFieldName        "Us";
       interpolation           true;
   }


Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle.
The *TangDrag* model is a model that calculates the particle based drag force
following the correlation of :ref:`Tang et al. (2015) <Tang2015>`.


Restrictions
""""""""""""

This model is strictly valid only for monodisperse gas-particle flows.


----------


.. _Tang2015:



**(Tang, 2015)**

Tang, Y., et al. "A new drag correlation from fully resolved simulations of flow
past monodisperse static arrays of spheres." AIChE journal 61.2 (2015): 688-698.
