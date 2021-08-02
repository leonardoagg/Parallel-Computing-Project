#!/bin/bash

#SBATCH --job-name input_generator
#SBATCH --error input_err_%j.txt
#SBATCH --output input_out_%j.txt
#SBATCH --mail-user leonardo.aggio@studenti.unipd.it
#SBATCH --mail-type ALL
#SBATCH --partition allgroups
#SBATCH --ntasks 1
#SBATCH --mem 4G
#SBATCH --time 2:00

srun input_generator.o 10000000
