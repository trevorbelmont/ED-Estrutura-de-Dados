#include <iostream>

using namespace std;

int main() {
  int *pointer = new int[5];

    cout << "pointer[3] é null : 0º" << endl;
    cout << pointer[3] << endl;

  for (int i = 0; i < 5; i++) {
    pointer[i] = i * 2;
  }

  cout << " pointer[3] é null : 1º" << endl;
  cout << pointer[3] << endl;

  delete[] pointer;

  if (pointer[3] == (int)NULL) {
    cout << " pointer[3] é null : 2º" << endl;
    cout << pointer[3] << endl;
  }
  cout << " pointer[3] NÃO é null NÃO : 2º" << endl;
    cout << pointer[3] << endl;
  

  return 0;
}