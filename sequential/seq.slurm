#!/bin/bash

#SBATCH --job-name seq_quicksort_OOO
#SBATCH --error sequencial_err_%j.txt
#SBATCH --output sequencial_out_%j.txt
#SBATCH --mail-user leonardo.aggio@studenti.unipd.it
#SBATCH --mail-type ALL
#SBATCH --partition allgroups
#SBATCH --ntasks 1
#SBATCH --mem 4G
#SBATCH --time 2:00

srun ./quicksort.o ../..data/
