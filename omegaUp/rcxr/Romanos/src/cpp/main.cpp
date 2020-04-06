// https://omegaup.com/arena/problem/Romanos

#include "bits/stdc++.h"

using namespace std;

int main() {
  // Todas las posibles combinaciones de unidades en romanos.
  vector<string> conversionUnidad{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
  // Todas las posibles combinaciones de decenas en romanos.
  vector<string> conversionDecena{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

  // Leer el número.
  int n;
  cin >> n;

  // Romper el número en su parte de unidades y de decenas en decimal.
  int unidadEnDecimal = n % 10;
  int decenaEnDecimal = n / 10;

  // Obtener la representación correspondiente en romanos.
  string unidadEnRomanos = conversionUnidad[unidadEnDecimal];
  string decenaEnRomanos = conversionDecena[decenaEnDecimal];

  // Imprimir el número en romanos.
  cout << decenaEnRomanos << unidadEnRomanos;
  return 0;
}
