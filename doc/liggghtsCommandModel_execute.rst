.. index:: liggghtsCommandModel execute

liggghtsCommandModel execute command
====================================

Syntax
""""""

Defined in :ref:`liggghtsCommmands <liggghtsCommands>`
dictionary.


.. parsed-literal::

   liggghtsCommandModels
   (
      execute
   );
   executeProps0
   {
       command
       (
           run
           $couplingInterval
       );
       runFirst             switch1;
       runLast              switch2;
       runEveryCouplingStep switch3;
       runEveryWriteStep    switch4;
       verbose;
   }

* *command* = LIGGGHTS command to be executed. Each word in a new line, numbers and symbols need special treatment (e.g. $couplingInterval will be replaced by correct coupling interval in the simulation)
* *switch1* = (optional, default off) if the command is executed only at first time step
* *switch2* = (optional, default off) if the command is executed only at last time step (requires *switch1* to be off)
* *switch3* = (optional, default off) if the command is executed at every coupling step (requires *switch1* and *switch2* to be off)
* *switch4* = (optional, default off) if the command is executed at every writing step (requires *switch1* to *switch3* to be off)
* *verbose* = (normally off) for verbose run


Examples
""""""""


.. parsed-literal::

   liggghtsCommandModels
   (
      execute
      execute
   );
   executeProps0
   {
       command
       (
           run
           $couplingInterval
       );
       runFirst             off;
       runLast              off;
       runEveryCouplingStep on;
   }
   executeProps1
   {
       command
       (
           write_restart
           noBlanks
           dotdot
           slash
           DEM
           slash
           liggghts.restart_
           timeStamp
       );
       runFirst             off;
       runLast              off;
       runEveryCouplingStep off;
       runEveryWriteStep    on;
   }

Description
"""""""""""

The *execute* liggghtsCommandModel can be used to execute a LIGGGHTS command
during a CFD run. In above example *execute\_0* for instance executes
"run $couplingInterval" every coupling step. *$couplingInterval* is automatically
replaced by the correct number of DEM steps. Additionally, *execute\_1* executes
"write\_restart ../DEM/liggghts.restart\_$timeStamp" every writing step, where
*$timeStamp* is automatically set.

.. note::

   These rather complex execute commands can be replaced by the
   *runLiggghts* and *writeLiggghts* commands!

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`liggghtsCommandModel <liggghtsCommandModel>`

