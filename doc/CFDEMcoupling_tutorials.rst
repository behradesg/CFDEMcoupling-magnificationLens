.. _1\_3:

Tutorials
=========

**General:**

Each solver of CFDEMcoupling comes with at least one tutorial example, showing
its functionality and correct usage. Provided that the installation is correct,
the tutorials can be run via "Allrun.sh" shell scripts. These scripts perform
all necessary steps (pre-processing, run, post-processing, visualization).

**Location:**

The tutorials can be found in the directory $CFDEM\_PROJECT\_DIR/tutorials,
which can be reached by typing *cfdemTut* in a CLI terminal.

**Structure:**

Each case is structured in a directory called "CFD" covering the CFD relevant
settings and data, and a directory called "DEM" covering the DEM relevant
settings and data. This allows to easily expand a pure CFD or DEM simulation
case to a coupled case.

**Usage:**

Provided that the installation is correct, the tutorials can be run via
"Allrun.sh" shell script, executed by typing "./Allrun.sh". The successful run
of the script might need some third party software (e.g. octave, evince, etc.).

**Settings:**

The main settings of a simulation are done via dictionaries:

The DEM setup of each case is defined by a `LIGGGHTS <lig_>`_ input file located in
$caseDir/DEM (e.g. in.liggghts\_init). For details on the LIGGGHTS setup,
please have a look at the LIGGGHTS manual.


Standard CFD settings are defined in $caseDir/CFD/constant (e.g.
transportProperties, RASproperties, etc.) and $caseDir/CFD/system (e.g.
fvSchemes, controlDict). You can find more information on that in
OpenFOAM\ |reg|\ (*) documentations.

.. |reg|    unicode:: U+000AE .. REGISTERED SIGN

Settings of the coupling routines are defined in
$caseDir/CFD/constant/:ref:`couplingProperties <couplingProperties>`
(e.g. force models, data exchange model, etc.) and
$caseDir/CFD/constant/:ref:`liggghtsCommands <liggghtsCommands>`
(allows to execute a LIGGGHTS command during a coupled simulation).


.. note::

   (*) This offering is not approved or endorsed by OpenCFD Limited, producer
   and distributor of the OpenFOAM software via www.openfoam.com, and owner of
   the OPENFOAM\ |reg| and OpenCFD\ |reg| trade marks.
   OPENFOAM\ |reg| is a registered trade mark of OpenCFD Limited, producer and
   distributor of the OpenFOAM software via www.openfoam.com.

.. |reg|    unicode:: U+000AE .. REGISTERED SIGN

.. _lig: http://www.cfdem.com

