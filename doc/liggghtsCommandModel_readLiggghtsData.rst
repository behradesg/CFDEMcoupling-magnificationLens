.. index:: liggghtsCommandModel readLiggghtsData

liggghtsCommandModel readLiggghtsData command
=============================================

Syntax
""""""

Defined in :ref:`liggghtsCommmands <liggghtsCommands>`
dictionary.


.. parsed-literal::

   liggghtsCommandModels
   (
      readLiggghtsData
   );
   readLiggghtsDataProps0
   {
       startIndex scalar1;
       verbose;
       exactTiming;
       filePath 
       (
           "word"
       );
       startTime    scalar2;
       endTime      scalar3;
       timeInterval scalar4;
   }

* *scalar1* = start index of data file to be read; the index is appended to *filePath*
* *verbose* = (default off) flag for verbose run
* *exactTiming* = flag indicating that start time should be kept even during a coupling interval
* *filePath* = path to LIGGGHTS data file. Each word starts in a new line; special characters, i.e. dots and slashes, need special treatment (e.g. dotdot will be replaced by "..")
* *scalar2* = start reading at this time
* *scalar3* = end reading at this time
* *scalar4* = repeat reading at this time interval while increasing the data file index


Examples
""""""""


.. parsed-literal::

   liggghtsCommandModels
   (
      readLiggghtsData
   );
   readLiggghtsDataProps0
   {
       startIndex 0;
       exactTiming;
       filePath 
       (
           dotdot
           slash
           DEM
           slash
           packing.data
       );
       startTime    0.002;
       endTime      0.012;
       timeInterval 0.001;
   }

Description
"""""""""""

The *readLiggghtsData* liggghtsCommandModel can be used to read LIGGGHTS data
files into LIGGGHTS during runtime of a coupled simulation. This corresponds to
the *read\_data* command in LIGGGHTS with the *add* option, i.e. read in
particles are added to existing particles.

.. warning::

   Model is outdated.

Related commands
""""""""""""""""

:doc:`liggghtsCommandModel <liggghtsCommandModel>`

