#sh1.sh
#!/bin/sh
#PBS -N sh1
#PBS -l nodes=1
pssh -h $PBS_NODEFILE mkdir -p /home/s2013631/sh1 1>&2
pscp -h $PBS_NODEFILE /home/s2013631/test1_arm /home/s2013631/sh1 1>&2
./test1_arm
