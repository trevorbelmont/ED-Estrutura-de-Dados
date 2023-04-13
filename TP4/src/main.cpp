#include <stdlib.h>

#include <iostream>
#include <string>

#include "fila_pilhada.hpp"

using namespace std;

void interface();
void test(int length);

int main(int argc, char *argv[]) {
  string function = "";

  if (argc > 1) {
    function = argv[1];
  }
  if (function == "interface") {
    interface();
    cout << argv[1];
  } else {
    test(10);
  }

  return 0;
}

void test(int length) {
  rQeuee q(length);

  cout << "Enfileira, rQeuee.push(), a Fila (FiFo): " << endl;
  for (int i = 0; i < length; i++) {
    int rndm = rand() % 10;
    cout << rndm << " ";
    q.push(rndm);
  }
  cout << endl;
  q.Fifo2Lifo();

  cout << "Desempilha ,rQeuee.pop(), fila convertida em pilha, rQeuee.Fifo2LiFo(): " << endl;
  for (int i = 0; i < length; i++) {
    // q.list();
    cout << q.pop() << " ";
  }
  cout << endl;
}

void interface() {
  int qSize;
  cout << "Define round qeuee size: " << endl;
  cin >> qSize;
  rQeuee q(qSize);

  char op;

  do {
    cout << "Press  opperation <char> :  ";
    cin >> op;

    switch (op) {
      case 'i':
        cout << "Enter int to insert it in the last, position:" << endl;
        int x;
        cin >> x;
        // cout << x * 4;
        q.push((int)x);
        break;

      case 'p':
        cout << q.pop() << endl;
        break;

      case 'l':
        q.list();
        break;

      case 'n':
          // cout << "Next index: " << q.pos() << endl;
          ;
        break;

      case 'f':
        cout << "front >> " << q.front() << endl;
      case 'e':
        cout << q.empty() << "<- Empty //  Size -> " << q.getSize() << " / " << q.getMaxSize() << endl;
        break;

      case 'c':  // change
        cout << "stored FiFo2LiFo" << endl;
        q.Fifo2Lifo();
        break;

      case 'q':
        exit(0);
        break;

      default:
        cout << "Opção não prevista. Use chars." << endl;
        break;
    }
  } while (op != 'q');  // q = quit
}