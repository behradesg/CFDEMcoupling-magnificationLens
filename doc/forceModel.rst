.. index:: forceModel

forceModel command
==================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       model_x
       model_y
   );

* model = name of force model to be applied

Examples
""""""""


.. parsed-literal::

   forceModels
   (
       Archimedes
       DiFeliceDrag
   );

.. note::

   This examples list might not be complete - please look for other models
   (forceModel XY) in this documentation.

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. All force models selected are
executed sequentially and the forces on the particles are superposed. If the
fluid density field is needed, by default a field named "rho" will be used. Via
the forceSubModel an alternative field can be chosen.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`Archimedes <forceModel_Archimedes>`, :doc:`DiFeliceDrag <forceModel_DiFeliceDrag>`,
:doc:`gradPForce <forceModel_gradPForce>`, :doc:`viscForce <forceModel_viscForce>`,
:doc:`dSauter <forceModel_dSauter>`

Default
"""""""

none

