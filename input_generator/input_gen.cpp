#include <stdio.h>     
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;


/*
Execute the program passing the number 
of elementes in the sequence
*/

int main(int argc, char *argv[]) 
{

  int len = atoi(argv[1]);

  /* initialize random seed: */
  srand (time(NULL));

  // output file creation
  ofstream outfile("inputSequence.txt");

  // generation of txt with 1 number for each row
  for(int i = 0 ; i < len ; i++)
  {
    outfile << rand() << endl;
  }

  //close file
  outfile.close();

  return 0;
}