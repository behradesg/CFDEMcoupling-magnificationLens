.. index:: forceModel fieldTimeAverage

forceModel fieldTimeAverage command
===================================

Syntax
""""""

Defined in couplingProperties dictionary.


.. parsed-literal::

   forceModels
   (
       fieldTimeAverage
   );
   fieldTimeAverageProps
   {
       startTime time;
       scalarFieldNames
       (
           "scalarField"
       );
       vectorFieldNames
       (
           "vectorField"
       );
   }

* *time* = (optional) time to start temporal averaging
* *scalarField* = names of the finite volume scalar fields to be temporally averaged
* *vectorField* = names of the finite volume vector fields to be temporally averaged


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       fieldTimeAverage
   );
   fieldTimeAverageProps
   {
       startTime 1.0;
       scalarFieldNames
       (
           "voidfraction"
       );
       vectorFieldNames
       (
           "Us"
       );
   }

Description
"""""""""""

This "force model" does not influence the particles or the simulation - it is a
post-processing tool! Starting at start time the specified fields are temporally
averaged and written at "writeTime". They can then be probed using standard
function object probes. The output name is timeAverage\_scalarField, where
scalarField is the name of the original field.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

