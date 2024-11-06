.. index:: dataExchangeModel

dataExchangeModel command
=========================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   dataExchangeModel model;

* model = name of data exchange model to be applied

Examples
""""""""


.. parsed-literal::

   dataExchangeModel twoWayFiles;
   dataExchangeModel twoWayMPI;

.. note::

   This examples list might not be complete - please look for other models
   (dataExchangeModel XY) in this documentation.

Description
"""""""""""

The data exchange model performs the data exchange between the DEM code and the
CFD code.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`noDataExchange <dataExchangeModel_noDataExchange>`,
:doc:`oneWayVTK <dataExchangeModel_oneWayVTK>`,
:doc:`twoWayFiles <dataExchangeModel_twoWayFiles>`,
:doc:`twoWayMPI <dataExchangeModel_twoWayMPI>`

Default
"""""""

none

