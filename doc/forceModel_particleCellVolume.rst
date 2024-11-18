.. index:: forceModel particleCellVolume

forceModel particleCellVolume command
=====================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       particleCellVolume
   );
   particleCellVolumeProps
   {
       upperThreshold scalar1;
       lowerThreshold scalar2;
       startTime      scalar3;
       verbose;
       writeToFile    switch1;
   }

* *scalar1* = only cells with a field value (magnitude) lower than this upper threshold are considered
* *scalar2* = only cells with a field value (magnitude) greater than this lower threshold are considered
* *scalar3* = (optional, default 0) start time of volume calculation and output
* *verbose* = (optional, default false) keyword only (mostly used for debugging)
* *switch1* = (optional, default false) switch for file output


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       particleCellVolume
   );
   particleCellVolumeProps
   {
       upperThreshold 0.999;
       lowerThreshold 0;
       verbose;
   }

Description
"""""""""""

This "force model" does not influence the particles or the simulation - it is a
post-processing tool! The total volume of the particles as they are represented
on the CFD mesh is calculated. Further the total volume of the cells particles
are in is calculated.

At "writeTime" a field named particleCellVolume, where scalarField is the name
of the original field, is written. This can then be probed using standard
function object probes. Analogously a field named cellVolume is written. Using
the *verbose* option a screen output is given.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

