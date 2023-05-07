#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "fila.hpp"
#include "pilha.hpp"

using namespace std;
int split(string str, char delim, string *splitted);

int main() {
  string exp = "5.997999 1 2 + 4 x 3.2 -";
  //getline(cin, input);
  string splitted[500];

  int tam = split(exp, ' ', splitted);

  cout << tam << endl;
  for (int i = 0; i < tam; i++)
    cout << splitted[i] << endl;

  double x = stod(splitted[0]);
  x -= 0.000002;
  cout << setprecision(7)<< x;
  return 0;
}

int split(string str, char delim, string *splitted) {
  // construct a stream from the string
  stringstream ss(str);

  string s;
  int i = 0;
  while (getline(ss, s, delim)) {
    splitted[i] = s;
    i++;
  }
  return i;
}
