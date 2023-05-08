#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// carrega todas as bibliotecas necessárias
#include "utils.hpp"
using namespace std;

int main() {
  cout << fixed << setprecision(6);  // Define precisão para o programa inteiro (até alteração)
  string exp = "2.668989  3.299435  5.577647  7.362147  *  7.919122  *  8.490275  8.332728  2.033447  *  /  -  /  /  2.387488  0.684457  4.372958  2.226028  /  8.153083  +  *  -  +  8.386214  /  9.354012  6.724427  *  1.525728  6.133841  2.985069  -  -  8.340931  -  1.530226  +  *  *  1.269565  2.045418  /  9.573261  +  7.561658  *  -  7.381152  /  6.284854  4.061986  /  /  5.954917  1.260094  8.387910  +  6.903085  /  5.802291  -  2.891419  -  *  2.144825  4.160590  *  /  6.450664  3.949879  /  7.150766  +  +  *  2.942184  8.179270  -  0.803171  9.760576  *  5.895433  /  -  8.016547  -  * ";

  Fila f = string2qeuee(exp);
  for (int i = 0; i < f.size(); i++) {
    cout << f.toString("  ") << endl;
    ;
  }

  cout << endl;
  cout << "double(3): " << stof(f.at(0)) << endl;
  return 0;
}
// 5 + ( ( 1 + 2 ) * 4 ) - 3