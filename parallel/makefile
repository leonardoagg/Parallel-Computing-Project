CXX = mpic++
SRC = main.cpp

all : quicksort_O1 quicksort_O2 quicksort_O3 quicksort

quicksort : $(SRC)
	$(CXX) -o $@.o $(SRC)

quicksort_O1 : $(SRC)
	$(CXX) -O1 -o $@.o $(SRC)

quicksort_O2 : $(SRC)
	$(CXX) -O2 -o $@.o $(SRC)

quicksort_O3 : $(SRC)
	$(CXX) -O3 -o $@.o $(SRC)

quicksort_O4 : $(SRC)
	$(CXX) -O4 -o $@.o $(SRC)


