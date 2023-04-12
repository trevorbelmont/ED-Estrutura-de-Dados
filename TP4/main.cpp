#include <iostream>

#include "fila_pilhada.hpp"

// descomentar encapsulamento (private in hpp)!

using namespace std;

int main() {
  rQeuee q(3);

  char op;

  do {
    cout << "Press  opperation <char> :  ";
    cin >> op;

    switch (op) {
      case 'i':
        cout << "Enter int to insert it in the last," << q.last << "ésima, position:" << endl;
        int x;
        cin >> x;
        // cout << x * 4;
        q.push((int)x);
        break;

      case 'p':
        q.pop();
        break;

      case 'l':
        for (int i = 0; i < q.getMaxSize(); i++) {
          if (q.first == i) cout << "f >> ";
          if (q.pos() == i) cout << "e >> ";
          cout << " >> " << q.get(i) << " [" << i << "]" << endl;
        }
        break;

      case 'n':
        cout << "Next index: " << q.pos();
        break;

      case 'g':
        cout << "f >> " << q.front() << endl;
      case 'e':
        cout << q.empty() << "<- Empty //  Size -> " << q.getSize() << " / " << q.getMaxSize() << endl;
        break;

      case 'q':
        exit(0);
        break;

      default:
        cout << "Opção não prevista. Use chars." << endl;
        break;
    }
  } while (op != 'q');  // q = quit

  return 0;
}
