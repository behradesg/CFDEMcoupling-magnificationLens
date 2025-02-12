.. index:: forceSubModel DeactivateFluidForces

forceSubModel DeactivateFluidForces command
==========================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
sub-dictionary of the force model in use.


.. parsed-literal::

   forceSubModels
   (
       DeactivateFluidForces;
   );
   DeactivateFluidForcesProps
   {
       
      insertionCellSetNames ( cellSetName );
   }   


Examples
""""""""


.. parsed-literal::

    forceSubModels
    (
       DeactivateFluidForces
    );
    DeactivateFluidForcesProps
    {
       
      insertionCellSetNames ( bottomInsertionCellSet );
    } 

Description
"""""""""""

It can be used in combination with fluid forces and Sets the 
fluid forces on the particles to zero in specified cellSets. 

Restrictions
""""""""""""
The cellset should be defined using topoSet command and 
stored in "constant/polyMesh/sets".

Related commands
""""""""""""""""

:doc:`forceSubModel <forceSubModel>`

