// https://omegaup.com/arena/problem/Bolsas-de-dulces

#include <iostream>
#include <vector>

using namespace std;

// Estructura para almacenar una venta parcial
struct VentaParcial {
  // Constructor
  VentaParcial(int articulos, int precioPorUnidad)
    : articulos(articulos)
    , precioPorUnidad(precioPorUnidad) {}
  // Cantidad de artículos vendidos
  int articulos;
  // Precio de cada artículo
  int precioPorUnidad;
};

// Calcula la venta total dada una lista de ventas parciales
int calcularVentaTotal(vector<VentaParcial> const& ventasParciales) {
  // 3.a. Empezar a acumular la venta total en una variable (inicializarla en 0)
  int resultado = 0;
  // 3.b. Hacer un ciclo del tamaño de las ventas parciales
  for (auto ventaParcial : ventasParciales) {
    // 3.b.i. Calcular venta parcial (cantidad de artículos vendidos x precio de cada artículo)
    // 3.b.ii. Agregar venta parcial a la venta total
    resultado += ventaParcial.articulos * ventaParcial.precioPorUnidad;
  }
  // 3.c. Una vez terminado el ciclo ya tienes el resultado del problema almacenado en tu variable venta total :)
  return resultado;
}

int main() {
  // 1. Leer número de ventas parciales (N) para saber el tamaño de ventas parciales
  int n;
  cin >> n;

  // 2. Leer datos de las ventas parciales
  vector<VentaParcial> ventasParciales;
  for (int i = 0; i < n; i++) {
    int articulos, precioPorUnidad;
    cin >> articulos >> precioPorUnidad;
    ventasParciales.emplace_back(articulos, precioPorUnidad);
  }

  // 3. Calcular la venta total
  int resultado = calcularVentaTotal(ventasParciales);

  // 4. Imprimir el resultado
  std::cout << resultado;
  return 0;
}
