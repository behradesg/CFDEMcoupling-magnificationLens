.. index:: forceSubModel ImExCorr

forceSubModel ImExCorr command
==============================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
sub-dictionary of the force model in use.


.. parsed-literal::

   forceSubModels
   (
       ImExCorr;
   );
   treatExplicit true;  // optional for some force models.
   treatDEM true;       // optional for some force models.
   implDEM true;        // optional for some force models.
   explicitInterpCorr true; // optional for some force models.

Examples
""""""""


.. parsed-literal::

   forceSubModels
   (
       ImExCorr;
   );
   treatExplicit true;  // optional for some force models.

Description
"""""""""""

Same as :doc:`ImEx <forceSubModel_ImEx>`, but it additionally reads
"explicitInterpCorr" to correct the error steming from interpolation of Ufluid
and averaging of Uparticles.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceSubModel <forceSubModel>`

