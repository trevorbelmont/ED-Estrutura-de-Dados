#include <stdlib.h>

#include <iomanip>
#include <iostream>

#include "heapSort.hpp"

using namespace std;

int main() {
  int array[100];

  randomArray(array, 100, 256);
  setprecision(2);
  list(array, 100);
}