#!/bin/bash
#------------------------------------------------------------------------------
# script for extracting the statistics in the DML region from the log file
#------------------------------------------------------------------------------ 
DATA1=log_run_periodic_box

grep --text 'TKESolid_DML:' $DATA1 | \
  cut -d' ' -f2 > TKECFDDEM.tmp 
 
grep --text 'slipVelocity_DML:' $DATA1 | \
  cut -d' ' -f2 > slipVelCFDDEM.tmp
 
grep --text 'PhiP2Solid_DML:' $DATA1 | \
  cut -d' ' -f2 > PhiP2CFDDEM.tmp

grep --text 'domainAveSolidsVolFrac_DML:' $DATA1 | \
  cut -d' ' -f2 > solidsMassCFDDEM.tmp

grep --text 'Time = ' $DATA1 | \
  grep -v Execution | cut -d' ' -f3 > time1.tmp

paste time1.tmp slipVelCFDDEM.tmp > slipVel_DMLRegionCFDDEM.txt
 
paste time1.tmp TKECFDDEM.tmp > TKEsolids_DMLRegionCFDDEM.txt

paste time1.tmp PhiP2CFDDEM.tmp > PhiP2_DMLRegionCFDDEM.txt

paste time1.tmp solidsMassCFDDEM.tmp > domainAveSolidsVolFrac_DMLRegionCFDDEM.txt

rm *.tmp

