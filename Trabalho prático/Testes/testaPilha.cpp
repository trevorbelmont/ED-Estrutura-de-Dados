#include <iostream>
#include <string>

#include "pilha.hpp"

using namespace std;

int main() {
  Pilha p(10);

  cout << p.empty() << endl;

  for (int i = 0; i < 10; i++) {
    p.insert(97 + i);
  }

  cout << p.full() << endl;

  cout << p.insert(4) << endl;
  cout << p.get() << endl
       << endl;

  for (int i = 0; i < 11; i++) {
    cout << p.pop() << " " << endl;
  }
  cout << p.empty() << endl;
}