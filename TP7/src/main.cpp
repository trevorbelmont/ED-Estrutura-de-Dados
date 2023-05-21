#include <iomanip>
#include <iostream>

#include "lista.hpp"

using namespace std;

int main() {
  Lista<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);
  // l.push_front(0);

  cout << endl;
  l.list();
  Lista<float> listFloat;
  // t.push_front(l.get(2));
  // t.push_front(l.get(0));
  listFloat.push_front(0.898);
  Node<double> doubleNode;
  // doubleNode.key = listFloat.at(0);

  doubleNode = *(l.get(0));

  cout << l.pop_front() << endl;
  auto it = l.get(1);
  l.erase(it);
  cout << l.pop_front() << endl;
  cout << "size: " << l.size() << endl;
  l.list();
  l.pop_back();
  l.list();
}
/* l
 00034
f 233
t 0010233 */