#include <stdlib.h>

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

#include "heapSort.hpp"
#include "shellSort.hpp"
using namespace std;

// testa as implementações de shellSort e heapsort ( h= log2 (size))
// implementadas de forma geneŕica para os tipos básicos
// Testa com arrays de tamanho 100, 100 vezes

// sintaxe do bin/exe: exe  1/0 size repeat seed max
int main(int argc, char* argv[]) {
  int size = 1000;
  string function = "shell";
  int repeat = 100;
  unsigned seed = unsigned(time(NULL));
  int max = 100;  // módulo do valor máximo gerado pelo rand.

  string aux;

  if (argc > 1) {
    aux = argv[1];
    if (aux == "heap") {
      function = "heap";
    } else if (aux == "shell") {
      function == "shell";
    } else if (aux == "compare") {
      function = "compare";
    }
  }
  if (argc >= 2) {
    size = atoi(argv[2]);
  }

  if (argc >= 3) {
    repeat = atoi(argv[3]);
  }
  if (argc >= 4) {
    seed = atoi(argv[4]);
  }
  if (argc >= 5) {
    max = unsigned(atoi(argv[5]));
  }
  cout << "Método: " << function << "  Array size: " << size << "  Repetições: " << repeat << "  Semente: " << seed << "  Range: +/-" << max << endl;

  int array[size];

  randomize(array, size, max, seed);

  cout << "random array: " << endl;
  list(array, size);
  cout << endl;

  if (function == "heap" || function == "compare") {
    cout << "array ordenado por HeapSort:" << endl;
    for (int i = 0; i < repeat; i++) {
      HeapSort(array, size - 1);  //(array2, size);
    }
    list(array, size);
    cout << " o array de tamanho " << size << " foi ordenado por heapSort " << repeat << " vezes." << endl;
  }

  if (function == "compare") {
    // usa a mesma semente para gerar o mesmo array "randômico"
    randomize(array, size, max, seed);
    cout << endl;
  }
  if (function == "shell" || function == "compare") {
    cout << "array ordenado por shelSort (log2 de size):" << endl;
    for (int i = 0; i < repeat; i++) {
      shellSort(array, size);  //(array2, size);
    }
    list(array, size);
    cout << " o array de tamanho " << size << " foi ordenado por shellsort " << repeat << " vezes." << endl;
  }
}
