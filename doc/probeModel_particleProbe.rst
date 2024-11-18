.. index:: probeModel particleProbe

probeModel particleProbe command
================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       forceModel1
       forceModel2
       forceModel3
   );

   probeModel particleProbe;

   particleProbeProps
   {
       particleIDsToSample (ID1 ID2 ID3 ...);  // list of particleIDs to sample
       verboseToFile;                          // main switch
       verbose;                                // currently not used
       printEvery xEvery;                      // print every this many CFD time steps
       sampleAll;                              // Activate sampling for all particles
       probeDebug;                             // probes additional fields
       includePosition;                        // will include particle position in the output file
       writePrecision xPrecision;              // number of significant digits to print
   }

* *forceModeli* = list of force models in the simulation, the particleProbe will be applied to all of these models!
* *particleIDsToSample* = list of particle IDs to be sampled.
* *verboseToFile* = main switch to activate the particle probe (default = off).
* *verbose* = main switch to activate output to Info (currently not implemented).
* *xEvery* = integer to specify the interval for sampling (default = 1, i.e., probing occurs every CFD time step).
* *sampleAll* = switch to activate sampling of all particles. Otherwise (default) only particles specified via "particleIDsToSample" in the couplingProperties dictionary will be sampled.
* *probeDebug* = switch to activate probing of debug properties of secondary importance (specific for each force model).
* *includePosition* = switch to add the particle position in the log file (default = off).
* *xPrecision* = number of significant digits of the text output (default = 3).


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       gradPForce
   );

   probeModel particleProbe;

   particleProbeProps
   {
       particleIDsToSample (0 1 2 3);
       verboseToFile;    // main switch
       verbose;          // currently not used
       printEvery 100;   // print every this many CFD time steps
       sampleAll;        // activate sampling for all particles
       probeDebug;       // probes additional fields
       includePosition;  // will include particle position in the output file
       writePrecision 4; // number of significant digits to print
   };

.. note::

   This examples list might not be complete - please check below for the list
   of models that can perform particle probing.

Description
"""""""""""

The *particleProbe* feature keeps track of per-particle quantities (e.g., the
fluid-particle interaction forces) acting on each DEM particle, and handles its
storage during the simulation. Data is saved in the 
$caseDir/CFD/particleProbes/startTime directory, where *startTime* is the time
at which the simulation is started (this avoids unwanted deletion of
particleProbe data).

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

The following force models are currently enabled for particle probing:

Archimedes, ArchimedesIB, BeetstraDrag, DiFeliceDrag, GidaspowDrag,
KochHillDrag, SchillerNaumannDrag, ShirgaonkarIB, virtualMassForce,
:doc:`gradPForce <forceModel_gradPForce>`, :doc:`viscForce <forceModel_viscForce>`,
:doc:`MeiLift <forceModel_MeiLift>`, that is most of the forceModels, see the
*src* directory for details, i.e. use


.. parsed-literal::

   grep -r 'probeM(' ./

in a CLI terminal.

Default
"""""""

none

