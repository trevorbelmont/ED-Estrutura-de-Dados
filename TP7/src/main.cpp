#include <stdlib.h>

#include <iomanip>
#include <iostream>

#include "heapSort.hpp"

using namespace std;

int main() {
  int array[100];

  randomize(array, 100, 256);
  list(array, 100);

  int* ptrArray;
  ptrArray = randomArray(100, 20);
  list(ptrArray, 8);
}