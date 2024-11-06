.. index:: forceModel MeiLift

forceModel MeiLift command
==========================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   forceModels
   (
       MeiLift
   );
   MeiLiftProps
   {
       velFieldName        "U";
       useShearInduced     switch1;
       useSpinInduced      switch2;
       combineShearSpin    switch3;
       treatForceExplicit  switch4;
       verbose             switch5;
       interpolation       switch6;
       scalarViscosity     switch7;
   }

* *U* = name of the finite volume fluid velocity field
* *useShearInduced* = (optional, default true) switch to activate shear-induced (Saffman) lift
* *useSpinInduced* = (optional, default false) switch to activate spin-induced (Magnus) lift
* *combineShearSpin* = (optional, default false) switch to use the correlation for combined shear- and spin-induced lift by :ref:`Loth and Dorgan (2009) <LothDorgan2009>`
* *switch4* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details
* *switch5* = (optional, default false) switch to activate the report of per-particle quantities to the screen
* *switch6* = (optional, default false) switch to activate tri-linear interpolation of the flow quantities at the particle position
* *switch7* = (optional, default false) sub model switch, see :doc:`forceSubModel <forceSubModel>` for details


Examples
""""""""


.. parsed-literal::

   forceModels
   (
       MeiLift
   );
   MeiLiftProps
   {
       velFieldName        "U";
       interpolation       true;
       verbose             true;
   }

Description
"""""""""""

The force model performs the calculation of forces (e.g. fluid-particle
interaction forces) acting on each DEM particle. The *MeiLift* model calculates
the lift force for each particle based on :ref:`Loth and Dorgan (2009) <LothDorgan2009>`.

.. _LothDorgan2009:



**(LothDorgan2009)** E. Loth, A.J. Dorgan. (2009):
"An equation of motion for particles of finite Reynolds number and size",
Environmental Fluid Mechanics

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`forceModel <forceModel>`

