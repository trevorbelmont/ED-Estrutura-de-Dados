#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "fila.hpp"
#include "pilha.hpp"

using namespace std;
int split(string str, char delim, string *splitted);

int main() {
  cout << fixed << setprecision(6); // Define precisão para o programa inteiro (até alteração)
  string exp = "2.668160  3.299435  5.577647  7.362147  *  7.919122  *  8.490275  8.332728  2.033447  *  /  -  /  /  2.387488  0.684457  4.372958  2.226028  /  8.153083  +  *  -  +  8.386214  /  9.354012  6.724427  *  1.525728  6.133841  2.985069  -  -  8.340931  -  1.530226  +  *  *  1.269565  2.045418  /  9.573261  +  7.561658  *  -  7.381152  /  6.284854  4.061986  /  /  5.954917  1.260094  8.387910  +  6.903085  /  5.802291  -  2.891419  -  *  2.144825  4.160590  *  /  6.450664  3.949879  /  7.150766  +  +  *  2.942184  8.179270  -  0.803171  9.760576  *  5.895433  /  -  8.016547  -  * ";
  //getline(cin, input);
  string splitted[1000];
  int tam = split(exp, ' ', splitted);

  cout << tam << endl;
  for (int i = 0; i < tam; i++)
    cout << splitted[i] << endl;

  double x = stod(splitted[0]);
   cout << x << endl << tam;
  return 0;
}

int split(string str, char delim, string *splitted) {
  // construct a stream from the string
  stringstream ss(str);

  string s;
  int i = 0;
  while (getline(ss, s, delim)) {
    splitted[i] = s;
    i++;
  }
  return i;
}
