# Parallel-Computing-Project
Progetto di calcolo parallelo Aggio Leonardo / Sarti Gioia

# Istruzioni

1) Creare una sequenza casuale di n cifre con il comando: 	./generator n

2) Eseguire il quicksort sequenziale usando il comando ./quicksort_seq ../input_generator/inputSequence.txt n

La sequenza messa a disposizione ha n = 10000 elementi.

- Compilare ed eseguire sequential su Linux:

  g++ quicksort.cpp -o sequential_quicksort
  ./sequential_quicksort ../input_generator/inputSequence.txt n
  
- Compilare ed eseguire parallel version su Linux:
  
  mpicxx -o parallel_quicksort main.cpp
  mpirun -np P ./parallel_quicksort ../input_generator/inputSequence.txt n
  
  (n = grandezza sequenza - P = Numero processori)
