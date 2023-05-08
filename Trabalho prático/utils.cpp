#include "utils.hpp"

#include <iostream>
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

int split(string mono, char delim, string *splitted) {
  stringstream ss(mono);
  string s;
  int i = 0;
  while (getline(ss, s, delim)) {
    if (s != " " && s != "") {
      splitted[i] = s;
      i++;
    }
  }
  return i;
}

bool checkDigits(string s) {
  int pointCount = 0;  // contador do número de pontos numa string

  // Passa por todas os caractere da string
  for (char c : s) {
    int cint = int(c);  // cast c para int

    // Se c algum carectere de s NÃO está entre '0' (48) e '9' (57) E tb não é '.' (46),
    // retorna falso - pois s não está no formato numérico esparado
    if (!(cint >= 48 && cint <= 57) && !(cint == 46)) {
      return false;
    }
    if (cint == 46) pointCount++;
  }
  // se todos caracteres da string são dígitos ou pontos (e há no máximo um ponto) retorna true
  return (pointCount <= 1);
}

int priority(string s) {
  if (s == "x" || s == "*" || s == "/")
    return 2;
  else if (s == "+" || s == "-")
    return 1;
  else
    return 0;
}

bool checkOperator(string s) {
  return (s == "x" || s == "*" || s == "/" || s == "+" || s == "-");
}
