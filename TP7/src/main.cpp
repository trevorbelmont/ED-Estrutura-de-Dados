#include <iomanip>
#include <iostream>
#include "lista.hpp"


using namespace std;

int main() {
  Lista<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  cout << l.size() << endl;
  cout << l.pop_front() << endl;
  cout << l.pop_back() << endl;
  cout << l.pop_front() << endl;
}
