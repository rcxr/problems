// https://omegaup.com/arena/problem/Bolsas-de-dulces

import java.util.Scanner;

// Clase para almacenar una venta parcial
class VentaParcial {
  // Constructor
  VentaParcial(int articulos, int precioPorUnidad) {
    this.articulos = articulos;
    this.precioPorUnidad = precioPorUnidad;
  }

  // Cantidad de articulos vendidos
  int articulos;
  // Precio de cada articulo
  int precioPorUnidad;
}

public class Main {
  // Calcula la venta total dada una lista de ventas parciales
  static int calcularVentaTotal(VentaParcial[] ventasParciales) {
    // 3.a. Empezar a acumular la venta total en una variable (inicializarla en 0)
    int resultado = 0;
    // 3.b. Hacer un ciclo del tamanio de las ventas parciales
    for (VentaParcial ventaParcial : ventasParciales) {
      // 3.b.i. Calcular venta parcial (cantidad de articulos vendidos x precio de cada articulo)
      // 3.b.ii. Agregar venta parcial a la venta total
      resultado += ventaParcial.articulos * ventaParcial.precioPorUnidad;
    }
    // 3.c. Una vez terminado el ciclo ya tienes el resultado del problema almacenado en tu variable venta total :)
    return resultado;
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    // 1. Leer numero de ventas parciales (N) para saber el tamanio de ventas parciales
    int n = in.nextInt();

    // 2. Leer datos de las ventas parciales
    VentaParcial[] ventasParciales = new VentaParcial[n];
    for (int i = 0; i < n; i++) {
      int articulos = in.nextInt();
      int precioPorUnidad = in.nextInt();
      ventasParciales[i] = new VentaParcial(articulos, precioPorUnidad);
    }

    // 3. Calcular la venta total
    int resultado = calcularVentaTotal(ventasParciales);

    // 4. Imprimir el resultado
    System.out.println(resultado);

    in.close();
  }
}
