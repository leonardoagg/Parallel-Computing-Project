#!/bin/bash

#SBATCH --job-name parallel_quicksort
#SBATCH --error quicksort_err_%j.txt
#SBATCH --output quicksort_out_%j.txt
#SBATCH --partition allgroups
#SBATCH --ntasks 8
#SBATCH -c 1
#SBATCH --mem 4G
#SBATCH --time 2:00

spack load intel-parallel-studio@professional.2019.4 

mpirun -np 8 ./quicksort.o ../input_generator/inputSequence.txt
