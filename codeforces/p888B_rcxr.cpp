// http://codeforces.com/problemset/problem/888/B

#include <iostream>
#include <vector>
#include <string>

int main() {
  // Numero de comandos
  int n;
  std::cin >> n;

  // Cadena de comandos
  std::string s;
  std::cin >> s;

  // Contadores para los 4 comandos
  int arriba = 0;
  int abajo = 0;
  int izquierda = 0;
  int derecha = 0;

  // Contar los comandos :)
  for (int i = 0; i < n; ++i) {
    switch (s[i]) {
      case 'U':
        ++arriba;
        break;
      case 'D':
        ++abajo;
        break;
      case 'L':
        ++izquierda;
        break;
      case 'R':
        ++derecha;
        break;
    }
  }

  // El maximo numero de comandos horizontales (izquierda|derecha) es igual
  // al doble del minimo de los dos comandos
  // Demostracion:
  // Sin perdida de generalidad digamos que hubo menos comandos izquierda (j)
  // que comandos derecha (k). No es posible que el robot haya atendido mas
  // de j comandos derecha y haber terminado en el origen (0, 0), porque si
  // eso pasara no habria forma de neutralizar los comandos derecha atendidos
  // con tan solo j comandos izquierda. Por lo tanto a lo mas se atendieron j
  // comandos derecha.
  // La opcion optima es cuando se atienden j comandos izquierda y j comandos
  // derecha.
  // Esto es el doble del minimo de los dos comandos! Que es lo que queriamos
  // demostrar. :)
  int max = izquierda < derecha ? 2 * izquierda : 2 * derecha;
  // Lo mismo aplica para los comandos verticales (arriba|abajo)
  max += arriba < abajo ? 2 * arriba : 2 * abajo;

  std::cout << max;
}
