// https://omegaup.com/arena/problem/Islotes/

#include "bits/stdc++.h"

using namespace std;

int main() {
  string palabra;
  cin >> palabra;

  int resultado = 0;

  for (int i = 1; i < palabra.length() - 1; i++) {
    // Se encuentra un islote solamente si un caracter es diferente a sus
    // vecinos y sus vecinos son iguales entre sí.
    if (palabra[i] != palabra[i - 1] && palabra[i - 1] == palabra[i + 1]) {
      resultado++;
    }
  }

  cout << resultado;

  return 0;
}
