forceModel pdCorrelation
========================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       pdCorrelation
   );
   pdCorrelationProps
   {
       coarseGrainingFactors
       (
           X Y Z
       );
       particleDensities
       (
           A B C
       );
       runOnWriteOnly true;
   }

* *coarseGrainingFactors* = list of coarse graining factors by type, separated by whitespace, optional
* *particleDensities* = list of particle densities by type, separated by whitespace, optional
* *runOnWriteOnly* = switch if this should be executed on write, optional (default: false - execute every coupling step).


Description
"""""""""""

This "forceModel" does not influence the particles or the flow - it calculates
the particle momentum-diameter correlation

.. image:: Eqs/pdCorrelation.png
   :align: center

where delta is the type-specific coarse-graining factor.

This model is sensitive to additionally pulled particle type info, and can
either use the type-specific densities from the dictionary or those pulled from
LIGGGHTS.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

