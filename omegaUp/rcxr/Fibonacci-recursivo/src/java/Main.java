// https://omegaup.com/arena/problem/Fibonacci-recursivo

import java.util.Scanner;

public class Main {

  static int ejecuciones;

//Fibonacci implementado recursivamente
  private static int fibonacciRecursivo(int i) {
    // TODO: implementa estos 3 pasos
    // 1. Incrementar el contador de llamadas recursivas (ejecuciones++)
    ejecuciones++;
    // 2. Atender casos base (fibonacci(0) := 0, fibonacci(1) := 1)
    if (i < 2) {
      return i;
    }
    // 3. Construir solución llamando recursivamente este mismo método
    return fibonacciRecursivo(i - 1) + fibonacciRecursivo(i - 2);
  }

  public static void main(String[] args) {
    // 1. Leer el Fibonacci deseado (i)
    Scanner in = new Scanner(System.in);
    int i = in.nextInt();

    // 2. Inicializar contador de llamadas recursivas
    ejecuciones = 0;

    // 3. Calcular el Fibonacci i usando el método recursivo
    int resultado = fibonacciRecursivo(i);

    // 4. Imprimir el Fibonacci i seguido del número de ejecuciones recursivas
    System.out.println(resultado + " " + ejecuciones);
    in.close();
  }
}
