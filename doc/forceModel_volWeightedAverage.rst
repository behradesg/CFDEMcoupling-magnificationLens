.. index:: forceModel volWeightedAverage

forceModel volWeightedAverage command
=====================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       volWeightedAverage
   );
   volWeightedAverageProps
   {
       startTime time;
       scalarFieldNames
       (
           scalarField
       );
       vectorFieldNames
       (
           vectorField
       );
       upperThreshold     scalar1;
       lowerThreshold     scalar2;
       verbose;
       writeToFile        switch1;
   }

* *time* = (optional, default 0.) time to start the averaging
* *scalarField* = names of the finite volume scalar fields to be temporally averaged
* *vectorField* = names of the finite volume vector fields to be temporally averaged
* *scalar1* = only cells with a field value (magnitude) lower than this upper threshold are considered
* *scalar2* = only cells with a field value (magnitude) greater than this lower threshold are considered
* *verbose* = (optional, default false) keyword only (mostly used for debugging)
* *switch1* = (optional, default false) switch for file output


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       volWeightedAverage
   );
   volWeightedAverageProps
   {
       startTime 0.1;
       scalarFieldNames
       (
           voidfraction
       );
       vectorFieldNames
       (
       );
       upperThreshold 0.999;
       lowerThreshold 0;
   }

Description
"""""""""""

This "forceModel" does not influence the particles or the simulation - it is a
post-processing tool! Starting at start time the volume weighted averages of
those cells of the fields within the threshold are calculated.

At "writeTime" a field named volAverage\_field, where scalarField is the name of
the original field, is written. This can then be probed using standard function
object probes.

Restrictions
""""""""""""


Currently all fields have the same threshold value!

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

