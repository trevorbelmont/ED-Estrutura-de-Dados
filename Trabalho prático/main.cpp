#include <iostream>
#include <string>

#include "pilha.hpp"
#include "fila.hpp"

using namespace std;

float avalia() {
  cout << "foi";
  float zero = 0.123456;
  return zero;
}

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

int main() {
  string exp = "5 1 2 + 4 x 3 -";

  Fila f(exp.length());

  f = carrega(exp);

  for (int i = 0; !f.empty(); i++) {
    cout << f.pop() << " ";
  }
  cout << endl;
  cout << f.size() << " full: " << f.full() << endl;

  return 0;
}
