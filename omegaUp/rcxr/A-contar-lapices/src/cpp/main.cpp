// https://omegaup.com/arena/problem/A-contar-lapices

#include "bits/stdc++.h"

using namespace std;

int main() {
  // Leer cantidad de lapices que se cayeron.
  int n;
  cin >> n;

  // Leer número de lápiz deseado.
  int lapizDeseado;
  cin >> lapizDeseado;

  // Empecemos a contar en cero la cantidad de lápices que son
  // del número de lápiz deseado.
  int respuesta = 0;

  // Leer los n lápices que se cayeron y ver cuántos son del
  // número deseado.
  for (int i = 0; i < n; i++) {
    int lapiz;
    cin >> lapiz;
    if (lapiz == lapizDeseado) {
      // Si el lápiz es del número deseado, subir el contador
      // que guarda la respuesta final.
      respuesta++;
    }
  }

  // Simplemente imprimir la respuesta.
  cout << respuesta;
  return 0;
}
