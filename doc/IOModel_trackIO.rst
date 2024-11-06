.. index:: IOModel trackIO

IOModel trackIO command
=======================

Syntax
""""""

Defined in :ref:`couplingProperties <couplingProperties>`
dictionary.


.. parsed-literal::

   IOModel trackIO;

Examples
""""""""


.. parsed-literal::

   IOModel trackIO;

Description
"""""""""""

The *trackIO* model is based on the :doc:`sophIO <IOModel_sophIO>` model and
additionally writes fields necessary to use the particleTracks utility (which
needs a particleTrackProperties file in the constant dir). The particleTracks
utility generates tracks of the particles and writes them to a VTK file.

Restrictions
""""""""""""


none

Related commands
""""""""""""""""

:doc:`IOModel <IOModel>`, :doc:`IOModel sophIO <IOModel_sophIO>`

