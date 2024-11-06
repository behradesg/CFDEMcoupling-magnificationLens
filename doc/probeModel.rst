.. index:: probeModel

probeModel command
==================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   probeModel model;
   modelProps
   {
   }

* model = name of the probeModel to be applied

Examples
""""""""


.. parsed-literal::

   probeModel off;

.. note::

   This examples list might not be complete - please check below for the list
   of probe models that can perform particle probing.

Description
"""""""""""

The *probeModel* feature allows to implement various probing features in CFDEM.
Currently, only the :doc:`particleProbe <probeModel_particleProbe>` model is
implemented, that performs probing of particle forces.

Use probe model *off* to disable this feature.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`probeModel off <probeModel_noProbe>`,
:doc:`probeModel particleProbe <probeModel_particleProbe>`

Default
"""""""

none

