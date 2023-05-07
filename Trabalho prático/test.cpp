#include <iostream>
#include <string>

using namespace std;

void printStrings(string *myArray, int tam) {
  myArray[2] = " boo !";
  for (int i = 0; i < tam; i++) {
    cout << myArray[i] << endl;
  }
}



int main() {
  string myStrings[3] = {"hello", "world", "!"};
  printStrings(myStrings, 3);
  cout << myStrings[2];
  
  return 0;
}
