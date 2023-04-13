#include <iostream>
#include <string>

#include "fibfat.hpp"

using namespace std;
using std::cin;
using std::cout;

int main(int argc, char *argv[]) {
  string function;
  int n, r;

  if (argc < 3 && argc > 4) {
    cout << "sintaxe: ff <rFat/iFat/rFib/iFib> <valor>" << endl
         << "ou" << endl;
    cout << "sintaxe: ff <rFat/iFat/rFib/iFib> <valor> <repetições>" << endl;
    return 1;
  } else {
    function = argv[1];
    n = stoi(argv[2]);
    r = (argc == 4) ? stoi(argv[3]) : 1;
  }

  if (function == "rFat") {
    for (int i = 0; i < r - 1; i++) {
      rFat(n);
    }
    cout << rFat(n) << endl;

    return 0;
  } else if (function == "iFat") {
    for (int i = 0; i < r - 1; i++) {
      iFat(n);
    }
    cout << iFat(n) << endl;
  }

  else if (function == "rFib") {
    for (int i = 0; i < r - 1; i++) {
      rFib(n);
    }
    cout << rFib(n) << endl;
  }

  else if (function == "iFib") {
    for (int i = 0; i < r - 1; i++) {
      iFib(n);
    }
    cout << iFib(n) << endl;
  } else {
    cout << "sintaxe: ff <rFat/iFat/rFib/iFib> <valor>" << endl;
    return 1;
  }
}
