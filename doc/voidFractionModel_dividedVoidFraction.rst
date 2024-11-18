.. index:: voidFractionModel divided

voidFractionModel divided command
=================================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   voidFractionModel divided;
   dividedProps
   {
       alphaMin       number1;
       interpolation;
       weight         number2;
       porosity       number3;
       procBoundaryCorrection switch1;
       verbose;
   }

* *number1* = minimum limit for void fraction
* *interpolation* = flag to interpolate void fraction to particle positions (normally off)
* *number2* = (optional) scaling of the particle volume to account for porosity or agglomerations.
* *number3* = (optional) diameter of the particle's representation is artificially increased according to *number2* \* Vparticle, volume remains unaltered!
* *switch1* = (optional, default false) allow for correction at processor boundaries. This requires the use of engineIB and vice versa.
* *verbose* = (optional, default false) flag for debugging output


Examples
""""""""


.. parsed-literal::

   voidFractionModel divided;
   dividedProps
   {
       alphaMin 0.2;
   }

Description
"""""""""""

The *divided* void fraction model is supposed to be used when a particle (or its
representation) is in the size range of a CFD cell. Satellite points are used to
divide the particle's volume to the touched cells.

The particle has radius R and its volume is divided into 29 non-overlapping
regions of equal volume. The centroids of these volumes are then used to
reproduce each volume. The first volume is a sphere with the center coinciding
with the particle center. The radius of this subsphere can be found as follows:

.. image:: Eqs/voidfractionModel_divided_pic2.png
   :align: center

The rest of the volume is a spherical layer that is divided into 2 layers of
equal volume. Position of the border between these two spherical layers in
radial direction can be easily obtained:

.. image:: Eqs/voidfractionModel_divided_pic3.png
   :align: center

Each of these spherical layers is later divided into 14 elements of equal volume.
Position of the centroid point in radial direction of each volume in the first
spherical layer is as follows

.. image:: Eqs/voidfractionModel_divided_pic4.png
   :align: center

Similarly, for the second spherical layer remembering that the external radius
is the particle radius:

.. image:: Eqs/voidfractionModel_divided_pic5.png
   :align: center

The region of influence of a particle can be increased artificially by
*porosity*\ , which blows up the particles, but keeps their volume (for
void fraction calculation) constant.

The particle volume occupied in the CFD domain can be adjusted by the parameter
*weight*\ , using

.. image:: Eqs/voidfractionModel_divided_pic6.png
   :align: center

In the basic implementation of solvers, the void fraction is calculated based on
all particles. Depending on the solver used, the void fraction calculation is
also performed for a certain type of particles.
The void fraction calculation is based on a three-step approach (reset, set and
interpolate), i.e. the void fraction is time interpolated from a previous and a
next void fraction field. Appropriate names for these fields have to be
specified in the sub-dictionaries voidFracFieldNamesPrev and
voidFracFieldNamesNext in the couplingProperties dictionary.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`voidFractionModel <voidFractionModel>`

