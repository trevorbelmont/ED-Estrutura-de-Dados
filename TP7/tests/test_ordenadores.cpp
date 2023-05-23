#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>

#include "heapSort.hpp"
#include "shellSort.hpp"
using namespace std;

int main() {
  int size = 10;

  int array[size];

  int array2[size];
  randomize(array, size, 20, -5);

  randomize(array2, size, 20, -5);
  array2[0] = array[0] = 0;
  cout << "array e array 2: " << endl;
  list(array, size);
  list(array2, size);

  /*
  size = 8;
  char array[size] = {"!ordenas"};
  char array2[size] = {"!ordenas"};

 */
  cout << "array ordenado por HeapSort:" << endl;

  HeapSort(array2, size - 1);  //(array2, size);
  list(array2, size);

  cout << "array ordenado por shelSort (log2 de size):" << endl;

  shellSort(array2, size);  //(array2, size);
  list(array2, size);
}