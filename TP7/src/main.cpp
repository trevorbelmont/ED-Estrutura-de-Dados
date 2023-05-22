#include <iomanip>
#include <iostream>

#include "lista_encadeada.hpp"

using namespace std;

int main() {
  Lista<string> ls;

  ls.push_back("back");

  // Implementando  os iteradores básicos faltantes.
  cout << (ls.end());
  cout << " Size: " << ls.size() << endl;
  cout << (ls.end()) << " [" << ls.end()->key << "] "
       << " -> prev: " << ls.end()->prev << " [" << ls.end()->prev->key << "] "
       << "Size: " << ls.size() << endl;
  ls.pop_back();
  cout << (ls.end()) << " [" << ls.end()->key << "] ";
  cout << " -> prev: " << ls.end()->prev << " [" << ls.end()->prev->key << "] ";
  cout << "Size: " << ls.size() << endl;
  ls.pop_front();
  cout << (ls.end()) << " [" << ls.end()->key << "] "
       << " -> prev: " << ls.end()->prev << " [" << ls.end()->prev->key << "] "
       << "Size: " << ls.size() << endl;

  ls.push_front("o");
  cout << (ls.end()) << " [" << ls.end()->key << "] "
       << " -> prev: " << ls.end()->prev << " [" << ls.end()->prev->key << "] "
       << "Size: " << ls.size() << endl;

  ls.push_front("ã");
  cout << (ls.end()) << " [" << ls.end()->key << "] "
       << " -> prev: " << ls.end()->prev << " [" << ls.end()->prev->key << "] "
       << "Size: " << ls.size() << endl;

  ls.insert("c", ls.begin());
  cout << (ls.end()) << " [" << ls.end()->key << "] "
       << " -> prev: " << ls.end()->prev << " [" << ls.end()->prev->key << "] "
       << "Size: " << ls.size() << endl;
  cout << "Insert [!,end()] : " << ls.insert("!", ls.end());
  cout << (ls.end()) << " [" << ls.end()->key << "] "
       << " -> prev: " << ls.end()->prev << " [" << ls.end()->prev->key << "] "
       << "Size: " << ls.size() << endl;
  cout << "push_back [?] : ";
  ls.push_back("?");

  ls.list();

  //---------------- POPPING OUT --------------------//

  cout << "Press any key to start popping out: ";
  char press;
  cin >> press;
  cout << endl
       << "Erasing Check:" << endl;
  cout << "ls.end():" << (ls.end()) << " [" << ls.end()->key << "] "
       << " -> prev: " << ls.end()->prev << " [" << ls.end()->prev->key << "] "
       << "Size: " << ls.size() << endl;
  cout << "erase [end().prev]: " << ls.erase(ls.end()->prev) << endl;
  cout << "ls.end():" << (ls.end()) << " [" << ls.end()->key << "] "
       << " -> prev: " << ls.end()->prev << " [" << ls.end()->prev->key << "] "
       << "Size: " << ls.size() << endl;
  cout << "erase [int 1]: " << ls.erase(1) << endl;
  cout << "ls.end():" << (ls.end()) << " [" << ls.end()->key << "] "
       << " -> prev: " << ls.end()->prev << " [" << ls.end()->prev->key << "] "
       << "Size: " << ls.size() << endl;
  cout << "erase [int 1]: " << ls.erase(1) << endl;

  ls.list();
  cout << "erase [end().prev]: " << ls.erase(ls.end()->prev) << endl;
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
  cout << endl;
  cout << endl;
  cout << "End tests." << endl;
}