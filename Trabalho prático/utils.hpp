#include "fila.hpp"
#include "pilha.hpp"

#include "string"

//(=(40)   0=(48)   9=(57)   +=(43)   -=(45)   *=(42)   /=(47)   )=(41)  
using namespace std;

Fila carrega(string s) {
  Fila aux(s.length());

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ')
      continue;
    else {
      char c = s[i];
      aux.push(c);
    }
  }

  return aux;
}