#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

#include "heapSort.hpp"

using namespace std;

int main() {
  int size = 10;

  /*
    int array[size];
    int array2[size];
    randomize(array, size, 20, -5);
    list(array, size);
    randomize(array2, size, 20, -5);
    list(array2, size);

   */
  size = 8;
  char array[size] = {"!ordenas"};
  char array2[size] = {"!ordenas"};

  cout << "Heapficando ambos: " << endl;

  // Meu buildHeap
  buildHeap(array, size);

  // Constrói heap segundo o slide
  constroiHeap(array2, size);

  list(array, size);
  cout << "Constŕoi Heap pelo Slide (ignora primeira entrada?!)" << endl;
  list(array2, size);
  HeapSort(array2, size - 1);  //(array2, size);
  list(array2, size);
}