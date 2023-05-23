#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

#include "heapSort.hpp"
#include "shellSort.hpp"
using namespace std;

// testa as implementações de shellSort e heapsort ( h= log2 (size))
// implementadas de forma geneŕica para os tipos básicos
// Testa com arrays de tamanho 100, 100 vezes

// sintaxe do bin/exe: string_sortType int_array_tam int_repetições
int main(int argc, char* argv[]) {
  int size = 100;
  string function = "shell";
  int repeat = 1;
  int array[size];
  unsigned int timed = unsigned(time(NULL));
  randomize(array, size, 20, timed);

  cout << "random array: " << endl;
  list(array, size);

  cout << "array ordenado por HeapSort:" << endl;

  for (int i = 0; i < repeat; i++) {
    HeapSort(array, size - 1);  //(array2, size);
  }
  list(array, size);

  cout << "array ordenado por shelSort (log2 de size):" << endl;
  for (int i = 0; i < repeat; i++) {
    shellSort(array, size);  //(array2, size);
  }
  list(array, size);
}
