#include <iomanip>
#include <iostream>

#include "lista.hpp"

using namespace std;

int main() {
  Lista<string> ls;

  //implementar os iteradores básicos faltantes.

  ls.push_front("o");
  ls.push_front("ã");
  ls.push_front("c");
  ls.push_back("!");
  ls.list();
  ls.erase(ls.end());
  ls.list();

  exit(0);
  Lista<int> l;
  // testar erase e insert com iteradores padrão (front, end, begin, last);
  cout << "vazia:" << l.empty() << endl;
  l.push_front(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);
  l.push_front(0);

  cout << endl;
  l.list();
  Lista<float> listFloat;
  // t.push_front(l.get(2));
  // t.push_front(l.get(0));
  listFloat.push_front(3.898);
  Node<double> doubleNode = *l.get(3);
  doubleNode.key = listFloat.at(0);  // pega o valor em float

  doubleNode = *l.get(0);             // pega o nodo da lista de int com key = 1 (int)
  Node<float> floatNode = *l.get(1);  // Reatribuição de Node de tipo deiferente não está acontecendo fora do construtor??
  cout << "Converted Double Node (1)? " << doubleNode.key << endl;
  cout << "Converted float Node  (2)? " << floatNode.key << endl;

  cout << l.pop_front() << endl;
  auto it = l.get(1);
  l.erase(it);
  cout << l.pop_front() << endl;
  cout << "size: " << l.size() << endl;
  l.list();
  l.pop_back();
  cout << "vazia:" << l.empty() << endl;

  l.list();
  l.clean();
  cout << "vazia:" << l.empty() << endl;
  l.list();
}