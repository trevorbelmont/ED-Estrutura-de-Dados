#include "utils.hpp"

#include <sstream>
#include <string>
using namespace std;

Fila string2qeuee(string exp) {
  string *tempSplitted = new string[500];
  int tam = split(exp, ' ', tempSplitted);
  Fila aux(tam);
  aux = aux.loadQeuee(tempSplitted, tam);
  delete[] tempSplitted;
  return aux;
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


