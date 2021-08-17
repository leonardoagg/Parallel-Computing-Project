#!/bin/bash

#SBATCH --job-name parallel_quicksort
#SBATCH --error quicksort_err_%j.txt
#SBATCH --output quicksort_out_%j.txt
#SBATCH --partition allgroups
#SBATCH --ntasks 8
#SBATCH -c 1
#SBATCH --mem 8G
#SBATCH --time 2:00

spack load intel-parallel-studio@professional.2019.4 

mpirun -np 8 ./quicksort_O1.o ../input_generator/inputSequence.txt
mpirun -np 8 ./quicksort_O2.o ../input_generator/inputSequence.txt
mpirun -np 8 ./quicksort_O3.o ../input_generator/inputSequence.txt

