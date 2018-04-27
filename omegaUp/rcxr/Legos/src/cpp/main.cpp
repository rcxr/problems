// https://omegaup.com/arena/problem/Legos
#include "bits/stdc++.h"

// Lambdas
std::function<bool(long long, long long)> izqDerMinLamda = [](long long a, long long b) { return a <= b; };
std::function<bool(long long, long long)> izqDerMaxLambda = [](long long a, long long b) { return a > b; };
std::function<bool(long long, long long)> derIzqMinLambda = [](long long a, long long b) { return a < b; };
std::function<bool(long long, long long)> derIzqMaxLambda = [](long long a, long long b) { return a >= b; };

// Busqueda binaria para encontrar la posicion en la que el lego con el valor pasado debe estar
unsigned find(
  std::vector<long long> const& legos,
  long long val,
  std::vector<std::pair<int, long long>> const& cache,
  int begin,
  int end,
  std::function<bool(long long, long long)>& lambda) {
  if (end <= begin) {
    return end;
  }
  int mid = (begin + end) / 2;
  if (lambda(legos[cache[mid].first], val)) {
    return find(legos, val, cache, mid + 1, end, lambda);
  }
  return find(legos, val, cache, begin, mid, lambda);
}

std::vector<long long> procesar(
  std::vector<long long> const& legos,
  std::function<bool(long long, long long)>& lambda) {
  // Estructura que recuerda las posiciones de los legos clave y los contadores
  // de a que otras piezas estos legos les ganan
  // - elem.first: indice
  // - elem.second: contador de otros legos contiguas que son dominados por este lego
  std::vector<std::pair<int, long long>> cache(legos.size());
  int cacheSize = 0;

  std::vector<long long> result(legos.size());
  for (int curr = 0; curr < legos.size(); ++curr) {
    cache[cacheSize].first = curr;
    cache[cacheSize].second = 1;
    // Se busca la posicion en el cache en el que se debe insertar este lego
    int index = find(legos, legos[curr], cache, 0, cacheSize, lambda);
    // Se calcula la cantidad de legos dominados por este lego
    result[curr] = cache[index].second + curr - cache[index].first;
    // Se trunca el cache ya que esta debe ser la ultima posicion
    cache[index].first = curr;
    cache[index].second = result[curr];
    cacheSize = index + 1;
  }

  return result;
}

int main() {
  // Leyendo numero de legos
  int n;
  std::cin >> n;

  // Leyendo legos
  std::vector<long long> legos(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> legos[i];
  }

  // Calculando numero de legos contiguos mayores de izquierda a derecha
  auto izqDerMin = procesar(legos, izqDerMinLamda);
  // Calculando numero de legos contiguos menores de izquierda a derecha
  auto izqDerMax = procesar(legos, izqDerMaxLambda);

  // Revirtiendo legos para contar de derecha a izquierda :p
  std::reverse(legos.begin(), legos.end());

  // Calculando numero de legos contiguos mayores de derecha a izquierda
  auto rightMin = procesar(legos, derIzqMinLambda);
  // Calculando numero de legos contiguos menores de derecha a izquierda
  auto rightMax = procesar(legos, derIzqMaxLambda);

  // Revirtiendo legos y resultados ya que estan al reves! :o
  std::reverse(legos.begin(), legos.end());
  std::reverse(rightMin.begin(), rightMin.end());
  std::reverse(rightMax.begin(), rightMax.end());

  // Calculando la belleza total
  long long belleza = 0;
  for (int i = 0; i < n; ++i) {
    // El lego i va a ser el menor en leftMax[i] * rightMax[i], estas veces va a tener que sumar su valor
    belleza += legos[i] * izqDerMax[i] * rightMax[i];
    // El lego i va a ser el mayor en leftMin[i] * rightMin[i], estas veces va a tener que restar su valor
    belleza -= legos[i] * izqDerMin[i] * rightMin[i];
  }

  // Imprimiendo resultado
  std::cout << belleza;
  return 0;
}
