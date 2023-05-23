#include <stdlib.h>

#include <iomanip>
#include <iostream>

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

  char array[size] = {"ordenas"};
  char array2[size] = {"ordenas"};
  size = 7;
  cout << "Heapficando ambos: " << endl;

  buildHeap(array, size);
  ConstroiHeap(array2, size);

  list(array, size);
  list(array2, size);
}