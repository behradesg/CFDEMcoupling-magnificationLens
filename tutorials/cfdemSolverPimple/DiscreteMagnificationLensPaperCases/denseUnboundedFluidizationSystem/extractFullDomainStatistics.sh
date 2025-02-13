#!/bin/bash
#------------------------------------------------------------------------------
# script for extracting the statistics in the full domain from the log file
#------------------------------------------------------------------------------  
DATA1=log_run_periodic_box

# Extract TKE of particle phase
grep --text 'TKE solid:' $DATA1 | \
  cut -d' ' -f3 > TKE.tmp 

# Extract domain averaged slip velocity
grep --text 'slip_velocity:' $DATA1 | \
  cut -d' ' -f2 > slipVel.tmp

# Extract domain averaged variance of solids volume fraction 
grep --text 'PhiP2:' $DATA1 | \
  cut -d' ' -f2 > PhiP2.tmp

# Extract time
grep --text 'Time = ' $DATA1 | \
  grep -v Execution | cut -d' ' -f3 > time1.tmp

paste time1.tmp slipVel.tmp > slipVel_FullDomain.txt
 
paste time1.tmp TKE.tmp > TKEsolids_FullDomain.txt

paste time1.tmp PhiP2.tmp > PhiP2_FullDomain.txt

rm *.tmp

