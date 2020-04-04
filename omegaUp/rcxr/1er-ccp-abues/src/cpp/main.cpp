// https://omegaup.com/arena/problem/1er-ccp-abues

#include "bits/stdc++.h"
#include <unordered_map>

using namespace std;

class MiembroDeFamilia {
public:
  MiembroDeFamilia() {
    this->hijxs = 0;
    this->nietxs = 0;
  }

  vector<MiembroDeFamilia *> padres;
  int hijxs;
  int nietxs;
};

class Familia {
public:
  // Agrega un miembro de la familia y actualiza sus relaciones con los demás.
  void registrar(string nombre, string mamaPapa) {
    // Actualizar a la mamá o al papá. Si no existe, agregarla.
    MiembroDeFamilia* mamaPapaMiembro = intentarAgregar(mamaPapa);
    mamaPapaMiembro->hijxs++;

    // Actualizar el miembro correspondiente al nombre. Si no existe, agregarlo.
    MiembroDeFamilia *miembro = intentarAgregar(nombre);
    miembro->padres.push_back(mamaPapaMiembro);
  }

  // Calcula el número de nietos de cada miembro de la familia, y regresa quienes
  // tienen la mayor cantidad de nietos.
  vector<string> calcularMasNietos() {
    // Todos reportan a sus respectivos padres cuantos nietos tienen por parte suya.
    for (pair<string, MiembroDeFamilia *> miembroPair : miembros) {
      MiembroDeFamilia *miembro = miembroPair.second;
      for (MiembroDeFamilia *mamaPapaMiembro : miembro->padres) {
        mamaPapaMiembro->nietxs += miembro->hijxs;
      }
    }

    // A estas alturas todos saben cuantos nietos tienen. Calcular el número mayor.
    int maxNietos = 0;
    for (pair<string, MiembroDeFamilia *> miembroPair : miembros) {
      MiembroDeFamilia *miembro = miembroPair.second;
      maxNietos = maxNietos < miembro->nietxs ? miembro->nietxs : maxNietos;
    }

    // Recolectar todos los familiares empatados. Ojo. Esta lista no está ordenada.
    vector<string> miembrosConMasNietos;
    for (pair<string, MiembroDeFamilia *> miembroPair : miembros) {
      if (miembroPair.second->nietxs == maxNietos) {
        miembrosConMasNietos.push_back(miembroPair.first);
      }
    }
    return miembrosConMasNietos;
  }

private:
  unordered_map<string, MiembroDeFamilia *> miembros;

  // Regresa el miembro de la familia correspondiente al nombre. Si no existe un miembro
  // de la familia con el nombre dado, entonces crea un nuevo miembro y lo agrega a la familia. 
  MiembroDeFamilia *intentarAgregar(string nombre) {
    // Revisar si existe ya un miembro con el nombre dado y regresarlo.
    unordered_map<string, MiembroDeFamilia *>::iterator miembroIt = miembros.find(nombre);
    if (miembroIt != miembros.end()) {
      return miembroIt->second;
    }

    // No existe un miembro con ese nombre. Crear uno y regresarlo.
    MiembroDeFamilia *miembro = new MiembroDeFamilia();
    miembros[nombre] = miembro;
    return miembro;
  }
};

int main() {
  Familia familia;

  int n;
  cin >> n;

  // Leer los n renglones e ir registrando las relaciones en la familia.
  for (int i = 0; i < n; i++) {
    string nombre, mamaPapa;
    cin >> nombre >> mamaPapa;
    familia.registrar(nombre, mamaPapa);
  }

  // Calcular los miembros de la familia con más nietos. Ordenar alfabéticamente.
  vector<string> miembros = familia.calcularMasNietos();
  sort(miembros.begin(), miembros.end());

  // Imprimir el resultado separado por espacios.
  for (string miembro : miembros) {
    cout << miembro << " ";
  }

  return 0;
}
