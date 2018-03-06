// https://omegaup.com/arena/problem/Fibonacci-recursivo

#include <iostream>

// Fibonacci implementado recursivamente
int fibonacciRecursivo(int i, int& ejecuciones) {
  // TODO: implementa estos 3 pasos
  // 1. Incrementar el contador de llamadas recursivas (ejecuciones++)
  ejecuciones++;
  // 2. Atender casos base (fibonacci(0) := 0, fibonacci(1) := 1)
  if (i < 2) {
    return i;
  }
  // 3. Construir solución llamando recursivamente este mismo método
  return fibonacciRecursivo(i - 1, ejecuciones) + fibonacciRecursivo(i - 2, ejecuciones);
}

int main() {
  // 1. Leer el Fibonacci deseado (i)
  int i;
  std::cin >> i;

  // 2. Inicializar contador de llamadas recursivas
  int ejecuciones = 0;

  // 3. Calcular el Fibonacci i usando el método recursivo
  int resultado = fibonacciRecursivo(i, ejecuciones);

  // 4. Imprimir el Fibonacci i seguido del número de ejecuciones recursivas
  std::cout << resultado << " " << ejecuciones;
  return 0;
}
