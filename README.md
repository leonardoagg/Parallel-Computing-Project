# Parallel-Computing-Project
Authors: 
- Aggio Leonardo
- Sarti Gioia 

## Instructions

### 1) Create a file which contains a sequence of n elements

`$ cd input_generator`

`$ make`

`$ ./input_generator.o 10000000`

change 1'000'000 with the number of elements you want.

### 2) Execute the sequential quicksort to order the sequence

`$ cd sequential`

`$ make`

`$ ./quicksort.o ../input_generator/inputSequence.txt`

### 3) Execute parallel versions of the quicksort

`$ cd parallel`

`$ make`

This command will create 4 executables:

- quicksort.o 
- quicksort_O1.o 
- quicksort_O2.o 
- quicksort_O3.o

`$ mpirun -np 4 ./quicksort.o ../input_generator/inputSequence.txt`

the number "4" indicates the number of parallel processes.

*Note*
Running quicksort.o with 1 process is the same of running the sequential version. 

"../input_generator/inputSequence.txt" can be replaced with another file with the same formatting.

