// http://codeforces.com/problemset/problem/489/C

#include <iostream>
#include <vector>

// Regresa cadena decreciente de digitos dando la suma dada
// Ejemplo: digitos = 3, suma = 20 => { 9, 9, 2 }
// Ejemplo: digitos = 5, suma = 20 => { 9, 9, 2, 0, 0 }
std::vector<int> construirCadenaOptima(int digitos, int suma) {
  std::vector<int> cadena;
  for (int i = 0; i < digitos; ++i) {
    if (9 <= suma) {
      // Si podemos tomar 9 de la suma, los tomamos
      cadena.push_back(9);
      suma -= 9;
    } else {
      // Si no podemos tomar 9, entonces tomamos lo que quede
      cadena.push_back(suma);
      suma = 0;
    }
  }
  return cadena;
}

int main() {
  int digitos;
  int suma;
  std::cin >> digitos >> suma;

  // Caso especial: suma es cero
  if (0 == suma) {
    // Si solo hay un digito, entonces tiene que ser cero
    if (1 == digitos) {
      std::cout << "0 0";
    } else {
      // Si hay mas de un digito regresar error
      std::cout << "-1 -1";
    }
    return 0;
  }

  // Caso especial: ni siquiera con puros 9s se puede alcanzar la suma
  if (9 * digitos < suma) {
    std::cout << "-1 -1";
    return 0;
  }

  // Imprimiendo el numero mas pequenio, que es mas dificil porque el primer
  // digito tiene que ser al menos 1

  // Primero hay que ver cual es el valor minimo del primer digito
  int primerDigito = suma - 9 * (digitos - 1);
  if (primerDigito < 1) {
    // El menor valor del primer digito es 1
    primerDigito = 1;
  }
  // Ahora solamente queda construir de forma optima el resto de la cadena
  std::vector<int> cadena = construirCadenaOptima(digitos - 1, suma - primerDigito);

  // Para imprimir, primero va el primer digito, despues la cadena optima
  std::cout << primerDigito;
  for (int i = 0; i < cadena.size(); ++i) {
    // La cadena esta en orden decreciente, y queremos el numero mas chico
    // entonces recorremos la cadena en orden inverso
    std::cout << cadena[cadena.size() - 1 - i];
  }
  std::cout << " ";

  // El segundo numero es mas facil ya que puede terminar en cero
  cadena = construirCadenaOptima(digitos, suma);
  // Simplemente imprimos la cadena optima
  for (int i = 0; i < cadena.size(); ++i) {
    std::cout << cadena[i];
  }
}
