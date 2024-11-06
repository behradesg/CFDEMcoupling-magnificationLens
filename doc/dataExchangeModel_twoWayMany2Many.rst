.. index:: dataExchangeModel twoWayMany2Many

dataExchangeModel twoWayMany2Many command
=========================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   dataExchangeModel twoWayMany2Many;
   twoWayMany2ManyProps
   {
       liggghtsPath "path";
   }

* *path* = path to the DEM simulation input file


Examples
""""""""


.. parsed-literal::

   dataExchangeModel twoWayMany2Many;
   twoWayMany2ManyProps
   {
       liggghtsPath "../DEM/in.liggghts_init";
   }

Description
"""""""""""

The data exchange model performs the data exchange between the DEM code and the
CFD code. The *twoWayMany2Many* model is a model that can exchange particle
properties from DEM to CFD and from CFD to DEM. Data is exchanged via MPI
technique using the many to many mapping scheme. The DEM run is executed by the
coupling model, via a *liggghtsCommandModel* object.

Restrictions
""""""""""""


Must be used in combination with the
:doc:`engineSearchMany2Many <locateModel_engineSearchMany2Many>` locate model!

Related commands
""""""""""""""""

:doc:`dataExchangeModel <dataExchangeModel>`

