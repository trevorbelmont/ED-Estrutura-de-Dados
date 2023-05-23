#include <stdlib.h>

#include <iomanip>
#include <iostream>

#include "heapSort.hpp"

using namespace std;

int main() {
  int size = 10;
  int array[size];

  int* ptrArray;
  ptrArray = randomArray(10, size);

  list(ptrArray, size);
  ptrArray = buildHeap(ptrArray, size);
  list(ptrArray, size);
}