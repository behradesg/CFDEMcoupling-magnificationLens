.. index:: forceSubModel ImEx

forceSubModel ImEx command
==========================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
sub-dictionary of the force model in use.


.. parsed-literal::

   forceSubModels
   (
       ImEx;
   );

Optional for some force models:


.. parsed-literal::

   treatForceExplicit                 true;
   treatForceDEM                      true;
   implForceDEM                       true;
   verbose                            true;
   interpolation                      true;
   useFilteredDragModel               true;
   useParcelSizeDependentFilteredDrag true;
   implForceDEMaccumulated            true;
   scalarViscosity                    true;

Examples
""""""""


.. parsed-literal::

   forceSubModels
   (
       ImEx;
   );
   treatForceExplicit true;  // optional for some force models.

Description
"""""""""""

If no force sub-model is applied *ImEx* is used as default. If the keyword
"forceSubModels" is provided, a choice of sub model is demanded. Depending on
the force model different keywords are read and can therefore be set
(see the log file). If the keyword is provided, its value is used.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceSubModel <forceSubModel>`

