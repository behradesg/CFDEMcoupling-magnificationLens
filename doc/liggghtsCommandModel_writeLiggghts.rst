.. index:: liggghtsCommandModel writeLiggghts

liggghtsCommandModel writeLiggghts command
==========================================

Syntax
""""""

Defined in :ref:`liggghtsCommmands <liggghtsCommands>`
dictionary.


.. parsed-literal::

   liggghtsCommandModels
   (
      writeLiggghts
   );
   //- optional
   writeLiggghtsProps
   {
       writeLast switch1;
       path      "path";
       writeName "name";
       overwrite switch2;
       verbose;
   }

* *switch1* = (optional, default on) select if only last step is stored or every write step
* *path* = (optional, default "../DEM") alternative path (relative to execution directory) for saving the restart file
* *name* = (optional, default "liggghts.restartCFDEM") name of the restart file to be written in ../DEM/
* *switch2* = (optional, default off) select if only one restart file $name or multiple files $name\_$timeStamp are written
* *verbose* = (optional, default off) for verbose run


Examples
""""""""


.. parsed-literal::

   liggghtsCommandModels
   (
      runLiggghts
      writeLiggghts
   );

Description
"""""""""""

The LIGGGHTS command models can be used to execute a LIGGGHTS command during a
CFD write. The *writeLiggghts* command executes the command
"write\_restart $name" - where $name is the name of the restart file - every
write step.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`liggghtsCommandModel <liggghtsCommandModel>`

