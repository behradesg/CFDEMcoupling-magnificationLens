The CFD-DEM cases for unbouned fluidization simulations
cf. Esgandari, Behrad, Daniel Queteschiner, Stefan Pirker, and Simon Schneiderbauer. 
"Discrete magnification lens model: A new hybrid multi-scale modelling method for fluid-particle systems." 
Powder Technology 445 (2024): 120094.

The simulation case related to the dilute unbounded fluidization system in the paper, is in "diluteUnboundedFluidizationSystem" folder.
This simulation corresponds to domian-averaged solids volume fraction of 0.05.

The simulation case related to the dense unbounded fluidization system in the paper, is in "denseUnboundedFluidizationSystem" folder.
This simulation corresponds to domian-averaged solids volume fraction of 0.20.

The simulation parameters are based on Table 6 in the paper.

To run the cases enter to each folder and type ./Allrun.sh in the terminal.

After simulation finishes, the statistics including domain averaged slip velocity, turbulent kinetic energy of particle phase and variance 
of particle volume fraction at each time-step can be extracted in the DML region using ./extractDMLRegionStatistics.sh and in the full domain using 
./extractFullDomainStatistics.sh.
