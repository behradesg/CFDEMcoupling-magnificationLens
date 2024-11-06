.. index:: otherForceModel gravityEff

otherForceModel gravityEff command
==================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   otherForceModels
   (
     gravityEff
   );
   gravityEffProps
   {
       voidfractionFieldName "voidfraction";
       rhoPart number1;
   }

* *voidfraction* = name of the finite volume void fraction field
* *number1* = particle density


Examples
""""""""


.. parsed-literal::

   otherForceModels
   (
     gravityEff
   );
   gravityEffProps
   {
     voidfractionFieldName "voidfraction";
     rhoPart 1500;
   }

Description
"""""""""""

An effective gravitational source term, *gravityEff*\ , that is necessery to drive
the flow only incase of periodic box simulations.
This source term is added to the momentum equation.
In case of simulating periodic boxes and assuming "homogeneous no-flow condition"
we will have:

.. image:: Eqs/otherForceModels_gravityEff_pic1.jpg
   :align: center

This equation depicts that in "no-flow condition" static pressure gradient balances the mixture weight.
Therefore, to derive the flow in periodic box simulations, a dynamic pressure gradient is defined as

.. image:: Eqs/otherForceModels_gravityEff_pic2.jpg
   :align: center

If one replaces the static pressure gradient of the fluid momentum equation with

.. image:: Eqs/otherForceModels_gravityEff_pic3.jpg
   :align: center

the fluid momentum equation solved in case of periodic box simulations will be

.. image:: Eqs/otherForceModels_gravityEff_pic4.jpg
   :align: center

The *gravityEff* source term is the third term on the RHS of the momentum equation.
Note that the gravitational body force of the fluid momentum equation is considered
with this source term.

In the basic implementation of *gravityEff*\ , first we calculate the density of
the mixture and then the source term is calculated based on the third term on the
RHS of the momentum equation.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`otherForceModels <otherForceModels>`

