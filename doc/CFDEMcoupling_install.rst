.. _1\_2:

Installation
============

In order to get the latest code version, please use the git repository at
`http://github.com <https://github.com/ParticulateFlow>`_.

Installing OpenFOAM
-------------------

Obtain a copy of the source code
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In the CFDEMcoupling repository take a look at the file


.. parsed-literal::

   src/lagrangian/cfdemParticle/cfdTools/versionInfo.H

to find out the latest tested version of LIGGGHTS and OpenFOAM that work with
CFDEMcoupling. As of this writing the version of OpenFOAM to be used is 6.

You can then basically follow the instructions at
`openfoam.org <https://openfoam.org/download/source/>`_, cloning OpenFOAM from the
git repository.


.. parsed-literal::

   cd $HOME
   mkdir OpenFOAM
   cd OpenFOAM
   git clone https://github.com/OpenFOAM/OpenFOAM-6.git

Clone the corresponding third party packages to the OpenFOAM folder.


.. parsed-literal::

   git clone https://github.com/OpenFOAM/ThirdParty-6.git

Switch to root user with sudo


.. parsed-literal::

   sudo su -

Install dependent packages required for OpenFOAM on Ubuntu by executing the
following commands:


.. parsed-literal::

   apt-get install build-essential flex bison git-core cmake zlib1g-dev libboost-system-dev libboost-thread-dev libopenmpi-dev openmpi-bin gnuplot libreadline-dev libncurses-dev libxt-dev
   apt-get install libqt5x11extras5-dev libxt-dev qt5-default qttools5-dev curl

.. note::

   Ubuntu 21.04 and newer dropped the *qt5-default* package. Instead use:


.. parsed-literal::

   apt-get install build-essential flex bison git-core cmake zlib1g-dev libboost-system-dev libboost-thread-dev libopenmpi-dev openmpi-bin gnuplot libreadline-dev libncurses-dev libxt-dev
   apt-get install libqt5x11extras5-dev libxt-dev qttools5-dev qttools5-dev-tools qtwebengine5-dev libqt5svg5-dev libqt5websockets5-dev libqt5xmlpatterns5 qtxmlpatterns5-dev-tools curl

Setup the environment
^^^^^^^^^^^^^^^^^^^^^

Open your bash startup file

.. note::

   Don't forget the dot before the file name of *.bashrc*


.. parsed-literal::

   gedit ~/.bashrc

and add the following lines:


.. parsed-literal::

   source $HOME/OpenFOAM/OpenFOAM-6/etc/bashrc
   export WM_NCOMPPROCS=4

Save the file and reload it:


.. parsed-literal::

   source ~/.bashrc


----------


**Additional check**

Open ~/OpenFOAM/OpenFOAM-6/etc/bashrc and make sure that *WM\_MPLIB* is set
correctly:


.. parsed-literal::

   export WM_MPLIB=SYSTEMOPENMPI

This should be the default setting but if you encounter some problems regarding
MPI you might have to download the openmpi-1.10.2 source package to the third
party folder and change the setting to *OPENMPI*


----------


Compile ThirdParty packages
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. parsed-literal::

   cd $WM_THIRD_PARTY_DIR
   ./Allwmake

**Compiling Paraview and the Paraview Reader Module**

Paraview is a third-party software provided for graphical post-processing in
OpenFOAM. Its compilation is automated using a script called makeParaView in the
ThirdParty-6 directory.

Before installing Paraview, check the version of cmake that is installed on the
system. This can be done by typing


.. parsed-literal::

   cmake --version

If the system cmake is older than version 2.8.8, clone a newer version to the
Third Party folder and compile it by executing the following:


.. parsed-literal::

   cd $WM_THIRD_PARTY_DIR
   git clone https://github.com/Kitware/CMake.git cmake-3.2.1
   cd cmake-3.2.1
   git checkout tags/v3.2.1
   cd ..
   ./makeCmake

In makeParaView set the path to cmake:


.. parsed-literal::

   CMAKE_PATH="$WM_THIRD_PARTY_DIR/platforms/linux64Gcc/cmake-3.2.1/bin"

To install Paraview, execute the following


.. parsed-literal::

   cd $WM_THIRD_PARTY_DIR
   ./makeParaView

If you get the following error


.. parsed-literal::

   VTK/ThirdParty/hdf5/vtkhdf5/src/H5detect.c:158:1: error: unknown type name ‘sigjmp_buf’
   static H5JMP_BUF jbuf_g;

in VTK/ThirdParty/hdf5/vtkhdf5/config/cmake/ConfigureChecks.cmake around line 445 change


.. parsed-literal::

   set (HDF5_EXTRA_FLAGS -D_DEFAULT_SOURCE -D_BSD_SOURCE)

to


.. parsed-literal::

   set (HDF5_EXTRA_FLAGS -D_GNU_SOURCE -D_DEFAULT_SOURCE -D_BSD_SOURCE)

Compile OpenFOAM
^^^^^^^^^^^^^^^^

**Compiling the source code**


.. parsed-literal::

   cd $WM_PROJECT_DIR
   ./Allwmake

**Testing the installation**

Create a project directory within the $HOME/OpenFOAM directory


.. parsed-literal::

   mkdir -p $FOAM_RUN

Copy the tutorial examples directory in the OpenFOAM distribution to the run
directory. If the OpenFOAM environment variables are set correctly, then the
following command will be correct:


.. parsed-literal::

   cp -r $FOAM_TUTORIALS $FOAM_RUN

Run the first example case of incompressible laminar flow in a cavity:


.. parsed-literal::

   cd $FOAM_RUN/tutorials/incompressible/icoFoam/cavity/cavity
   blockMesh
   icoFoam
   paraFoam

Installing CFDEMcoupling
------------------------

Make sure OpenFOAM is set up correctly and LIGGGHTS is installed as well. Clone
the CFDEMcoupling source from the repository:


.. parsed-literal::

   cd $HOME
   mkdir CFDEM
   cd CFDEM
   git clone https://github.com/ParticulateFlow/CFDEMcoupling.git

Open the bashrc file of CFDEMcoupling


.. parsed-literal::

   gedit ~/CFDEM/CFDEMcoupling/etc/bashrc &

Edit the lines marked as *USER EDITABLE PART* to reflect your installation paths
correctly. Save the bashrc file and reload it:


.. parsed-literal::

   source ~/CFDEM/CFDEMcoupling/etc/bashrc

Entering $CFDEM\_PROJECT\_DIR in a the terminal should now give "... is a directory"

Check if everything is set up correctly:


.. parsed-literal::

   cfdemSysTest

Compile LIGGGHTS (as a library)


.. parsed-literal::

   cfdemCompLIG

If the compilation fails with a message like


.. parsed-literal::

   No rule to make target '/usr/lib/libpython2.7.so'

you probably need to create a symbolic link to the library in question.

Compile CFDEMcoupling (library, solvers and utilities) in one go


.. parsed-literal::

   cfdemCompCFDEM

or alternatively step by step


.. parsed-literal::

   cfdemCompCFDEMsrc
   cfdemCompCFDEMsol
   cfdemCompCFDEMuti

Find the log files of the compile process


.. parsed-literal::

   cd ~/CFDEM/CFDEMcoupling/etc/log
   ls

If the file **log\_compile\_results\_success** is present, compilation was successful.

Install Octave for post-processing some of the tutorial output.


.. parsed-literal::

   sudo apt-get install octave

To run all tutorial cases type in a terminal:


.. parsed-literal::

   cfdemTestTUT

