#include <iostream>
#include <string>

#include "fila.hpp"
#include "pilha.hpp"

using namespace std;

int main() {
  string exp = "5 1 2 + 4 x 3 -";

  Fila f(exp.length());

  f = f.exp2qeuee(exp);

  cout << f.size() << " full: " << f.full() << endl;

  for (int i = 0; !f.empty(); i++) {
    char c = f.pop();
    cout << c << " ";//"=(" << int(c) << ")   ";
  }
  cout << endl;
  cout << f.size() << " full: " << f.full() << endl;

  return 0;
}
