.. index:: dataExchangeModel\_twoWayOne2One

dataExchangeModel\_twoWayOne2One command
========================================

Syntax
""""""

Defined in couplingProperties dictionary.


.. parsed-literal::

   dataExchangeModel twoWayOne2One;
   twoWayOne2OneProps
   {
       liggghtsPath     "path";
       useStaticProcMap switch1;
   };

* *path*   = path to the DEM simulation input file
* *switch1* = (optional, default no) switch to determine if the map is built once (yes) or every coupling step (no)


Examples
""""""""


.. parsed-literal::

   dataExchangeModel twoWayOne2One;
   twoWayOne2OneProps
   {
       liggghtsPath     "../DEM/in.liggghts_init";
       useStaticProcMap yes;
   }

Description
"""""""""""

The data exchange model performs the data exchange between the DEM code and the CFD code. The twoWayOne2One model is a model that can exchange particle properties from DEM to CFD and from CFD to DEM. Data is exchanged via MPI technique using a more sophisticated mapping scheme than twoWayMPI / all2all and scales much better for large systems and many cores. The DEM run is executed by the coupling model, via a liggghtsCommandModel object. Only use staticProcMap yes if no load balancing is employed.

Restrictions
""""""""""""


Must be used in combination with the engineSearchMany2Many locate model! Use the "one2one" cfd datacoupling option in fix couple/cfd in LIGGGHTS!

Some warnings may be given for particles that have not been located - this is due to LIGGGHTS' treatment of domain crossers.

Related commands
""""""""""""""""

:doc:`dataExchangeModel <dataExchangeModel>`

