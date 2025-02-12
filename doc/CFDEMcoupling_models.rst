.. _1\_6:

.. _comm:

Models
============================

This section lists all CFDEMcoupling sub-models alphabetically, with
a separate listing below of styles within certain commands.

I/O models
----------

The :doc:`IOModel <IOModel>` keyword entry specifies the model for writing output
data.

+----------------------------------+----------------------------------+
| :doc:`basicIO <IOModel_basicIO>` | :doc:`off <IOModel_noIO>`        |
+----------------------------------+----------------------------------+
| :doc:`sophIO <IOModel_sophIO>`   | :doc:`trackIO <IOModel_trackIO>` |
+----------------------------------+----------------------------------+

Averaging models
----------------

The :doc:`averagingModel <averagingModel>` keyword entry defines the model used to
map the Lagrangian data to Eulerian values.

+-------------------------------------+---------------------------------------+
| :doc:`dense <averagingModel_dense>` | :doc:`dilute <averagingModel_dilute>` |
+-------------------------------------+---------------------------------------+
| off                                 |                                       |
+-------------------------------------+---------------------------------------+

Chemistry models
----------------

The :doc:`chemistryModels <chemistryModel>` keyword is used to specify a list of
models used for chemical reaction calculations.

+---------------------------------------------------------------------+-----------------------------------------+
| :doc:`diffusionCoefficients <chemistryModel_diffusionCoefficients>` | initMultiLayers                         |
+---------------------------------------------------------------------+-----------------------------------------+
| :doc:`massTransferCoeff <chemistryModel_massTransferCoeff>`         | :doc:`off <chemistryModel_noChemistry>` |
+---------------------------------------------------------------------+-----------------------------------------+
| :doc:`reactantPerParticle <chemistryModel_reactantPerParticle>`     | :doc:`species <chemistryModel_species>` |
+---------------------------------------------------------------------+-----------------------------------------+

Clock models
------------

The :doc:`clockModel <clockModel>` keyword entry specifies the model used to
examine the CFDEMcoupling code with respect to runtime.

+---------------------------------+-------------------------------------------------+
| :doc:`off <clockModel_noClock>` | :doc:`standardClock <clockModel_standardClock>` |
+---------------------------------+-------------------------------------------------+

Data exchange models
--------------------

The :doc:`dataExchangeModel <dataExchangeModel>` keyword entry specifies the model
that performs the data exchange between the DEM code and the CFD code.

+------------------------------------------------------------+--------------------------------------------------------+
| :doc:`noDataExchange <dataExchangeModel_noDataExchange>`   | :doc:`oneWayVTK <dataExchangeModel_oneWayVTK>`         |
+------------------------------------------------------------+--------------------------------------------------------+
| :doc:`twoWayFiles <dataExchangeModel_twoWayFiles>`         | :doc:`twoWayMPI <dataExchangeModel_twoWayMPI>`         |
+------------------------------------------------------------+--------------------------------------------------------+
| :doc:`twoWayMany2Many <dataExchangeModel_twoWayMany2Many>` | :doc:`twoWayOne2One <dataExchangeModel_twoWayOne2One>` |
+------------------------------------------------------------+--------------------------------------------------------+

Diffusion coefficient models
----------------------------

The *diffCoeffModel* keyword entry specifies the model for the diffusion
coefficient of dissolved spieces in the fluid phase in the presence of particles.

+------------------+-----+
| SyamlalDiffCoeff | off |
+------------------+-----+

Energy models
-------------

The *energyModels* keyword specifies a list of energy models used for e.g.
compressible, reacting flows.

+--------------------------+------------------------+
| heatTransferGunn         | heatTransferInterGrain |
+--------------------------+------------------------+
| heatTransferRanzMarshall | reactionHeat           |
+--------------------------+------------------------+
| wallHeatTransferYagi     |                        |
+--------------------------+------------------------+

Force models
------------

The :doc:`forceModels <forceModel>` keyword specifies a list of models that exert
a force on each DEM particle.

+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`Archimedes <forceModel_Archimedes>`                                | :doc:`ArchimedesIB <forceModel_ArchimedesIB>`                       |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`BeetstraDrag <forceModel_BeetstraDrag>`                            | BeetstraDragPoly                                                    |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`DiFeliceDrag <forceModel_DiFeliceDrag>`                            | Fines                                                               |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`GidaspowDrag <forceModel_GidaspowDrag>`                            | :doc:`KochHillDrag <forceModel_KochHillDrag>`                       |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`LaEuScalarTemp <forceModel_LaEuScalarTemp>`                        | :doc:`MeiLift <forceModel_MeiLift>`                                 |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`ParmarBassetForce <forceModel_ParmarBassetForce>`                  | :doc:`SchillerNaumannDrag <forceModel_SchillerNaumannDrag>`         |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`ShirgaonkarIB <forceModel_ShirgaonkarIB>`                          | :doc:`TangDrag <forceModel_TangDrag>`                               |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`dSauter <forceModel_dSauter>`                                      | deactivateForce                                                     |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| directedDiffusiveRelaxation                                              | evaluateFluctuations                                                |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`fieldStore <forceModel_fieldStore>`                                | :doc:`fieldTimeAverage <forceModel_fieldTimeAverage>`               |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| freeStreaming                                                            | :doc:`gradPForce <forceModel_gradPForce>`                           |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`gradPForceSmooth <forceModel_gradPForceSmooth>`                    | granKineticEnergy                                                   |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`interface <forceModel_interface>`                                  | isotropicFluctuations                                               |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`noDrag <forceModel_noDrag>`                                        | :doc:`particleCellVolume <forceModel_particleCellVolume>`           |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| particleDeformation                                                      | :doc:`pdCorrelation <forceModel_pdCorrelation>`                     |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| potentialRelaxation                                                      | :doc:`staticPressure <forceModel_staticPressure>`                   |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`surfaceTensionForce <forceModel_surfaceTensionForce>`              | terminalVelocity                                                    |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`transferFluidProperties <forceModel_transferFluidProperties>`      | turbulentDispersion                                                 |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| turbulentVelocityFluctuations                                            | :doc:`virtualMassForce <forceModel_virtualMassForce>`               |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`viscForce <forceModel_viscForce>`                                  | :doc:`volWeightedAverage <forceModel_volWeightedAverage>`           |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+
| :doc:`particleVelocityController <forceModel_particleVelocityController>`|                                                                     |
+--------------------------------------------------------------------------+---------------------------------------------------------------------+

Force sub-models
^^^^^^^^^^^^^^^^

The :doc:`forceSubModels <forceSubModel>` keyword specifies a list
of models that hold settings for a force model.

+----------------------------------+--------------------------------------------------------------------+
| :doc:`ImEx <forceSubModel_ImEx>` | ScaleForce                                                         |
+----------------------------------+--------------------------------------------------------------------+
| scaleForceBoundary               | :doc:`DeactivateFluidForces <forceSubModel_DeactivateFluidForces>` |
+----------------------------------+--------------------------------------------------------------------+

.. _lcm:

LIGGGHTS command models
---------------------------------

The :doc:`liggghtsCommandModels <liggghtsCommandModel>` keyword specifies a list
of models that execute LIGGGHTS commands within a CFD run.

+-------------------------------------------------------+-----------------------------------------------------------------+
| :doc:`execute <liggghtsCommandModel_execute>`         | :doc:`readLiggghtsData <liggghtsCommandModel_readLiggghtsData>` |
+-------------------------------------------------------+-----------------------------------------------------------------+
| :doc:`runLiggghts <liggghtsCommandModel_runLiggghts>` | :doc:`writeLiggghts <liggghtsCommandModel_writeLiggghts>`       |
+-------------------------------------------------------+-----------------------------------------------------------------+

Locate models
-------------

The :doc:`locateModel <locateModel>` keyword entry specifies the model used to
search the CFD mesh for the CFD cell corresponding to a given position.

+------------------------------------------------------------------+----------------------------------------------+
| :doc:`engine <locateModel_engineSearch>`                         | :doc:`engineIB <locateModel_engineSearchIB>` |
+------------------------------------------------------------------+----------------------------------------------+
| :doc:`engineSearchMany2Many <locateModel_engineSearchMany2Many>` | :doc:`standard <locateModel_standardSearch>` |
+------------------------------------------------------------------+----------------------------------------------+
| :doc:`turboEngine <locateModel_turboEngineSearch>`               |                                              |
+------------------------------------------------------------------+----------------------------------------------+

Mass transfer models
--------------------

The *massTransferModels* keyword specifies a list of mass transfer models used
for evaluating species transfer between particles and fluids.

+------------------+
| massTransferGunn |
+------------------+

Mesh motion models
------------------

The :doc:`meshMotionModel <meshMotionModel>` keyword entry specifies the model
used to manipulate the CFD mesh according to the DEM mesh motion.

+----------------------------------------------------+
| :doc:`noMeshMotion <meshMotionModel_noMeshMotion>` |
+----------------------------------------------------+

Momentum coupling models
------------------------

The :doc:`momCoupleModels <momCoupleModel>` keyword specifies a list of models
used for momentum exchange between DEM and CFD simulation

+-------------------------------------------------------+-------------------------------------------------------+
| deactivateCouple                                      | :doc:`explicitCouple <momCoupleModel_explicitCouple>` |
+-------------------------------------------------------+-------------------------------------------------------+
| :doc:`implicitCouple <momCoupleModel_implicitCouple>` | :doc:`off <momCoupleModel_noCouple>`                  |
+-------------------------------------------------------+-------------------------------------------------------+

Other force models
------------------

The *otherForceModels* keyword specifies a list of models that exert a force on
each DEM particle.

+------------------------------------------------+-------------------------------+
| expParticleForces                              | gravity                       |
+------------------------------------------------+-------------------------------+
| :doc:`gravityEff <otherForceModel_gravityEff>` | secondaryPhaseInducedBuoyancy |
+------------------------------------------------+-------------------------------+
| weightSecondaryPhase                           |                               |
+------------------------------------------------+-------------------------------+

Probe models
------------

The :doc:`probeModel <probeModel>` keyword entry specifies the probing features in
CFDEMcoupling simulations.

+---------------------------------+-------------------------------------------------+
| :doc:`off <probeModel_noProbe>` | :doc:`particleProbe <probeModel_particleProbe>` |
+---------------------------------+-------------------------------------------------+

Region models
-------------

The :doc:`regionModel <regionModel>` keyword entry specifies the model used to
select a certain region for coupled simulations.

+------------------------------------------+
| :doc:`allRegion <regionModel_allRegion>` |
+------------------------------------------+

Smoothing models
----------------

The :doc:`smoothingModel <smoothingModel>` keyword entry specifies the model for
smoothing the exchange fields.

+-------------------------------------------------------------------------------------+---------------------------------------------------------------+
| :doc:`constDiffAndTemporalSmoothing <smoothingModel_constDiffAndTemporalSmoothing>` | :doc:`constDiffSmoothing <smoothingModel_constDiffSmoothing>` |
+-------------------------------------------------------------------------------------+---------------------------------------------------------------+
| :doc:`off <smoothingModel_noSmoothing>`                                             | :doc:`temporalSmoothing <smoothingModel_temporalSmoothing>`   |
+-------------------------------------------------------------------------------------+---------------------------------------------------------------+
| :doc:`laplaceFilterSmoothing <smoothingModel_laplaceFilterSmoothing>`               |:doc:`constDiffSmoothingF <smoothingModel_constDiffSmoothingF>`|
+-------------------------------------------------------------------------------------+---------------------------------------------------------------+

Thermal conductivity models
---------------------------

The *thermCondModel* keyword entry specifies the model for the thermal
conductivity of the fluid phase in the presence of particles.

+------------------+---------------------------+
| SyamlalThermCond | ZehnerSchluenderThermCond |
+------------------+---------------------------+
| off              |                           |
+------------------+---------------------------+

Void fraction models
--------------------

The :doc:`voidFractionModel <voidFractionModel>` keyword entry specifies the model
accounting for the volume of the particles in the CFD domain.

+----------------------------------------------------------------+------------------------------------------------------+
| :doc:`Gauss <voidFractionModel_GaussVoidFraction>`             | :doc:`IB <voidFractionModel_IBVoidFraction>`         |
+----------------------------------------------------------------+------------------------------------------------------+
| :doc:`bigParticle <voidFractionModel_bigParticleVoidFraction>` | :doc:`centre <voidFractionModel_centreVoidFraction>` |
+----------------------------------------------------------------+------------------------------------------------------+
| :doc:`divided <voidFractionModel_dividedVoidFraction>`         | off                                                  |
+----------------------------------------------------------------+------------------------------------------------------+
| trilinear                                                      |                                                      |
+----------------------------------------------------------------+------------------------------------------------------+

transfer data to LIGGGHTS models
--------------------------------

The :doc:`transferDataModels <transferDataModels>` keyword entry specifies the 
face and cell based data transfer to LIGGGHTS.

+----------------------------------------------------------------+---------------------------------------------------------------+
| :doc:`transferCellData <transferDataModels_transferCellData>`  | :doc:`transferFaceData <transferDataModels_transferFaceData>` |
+----------------------------------------------------------------+---------------------------------------------------------------+

