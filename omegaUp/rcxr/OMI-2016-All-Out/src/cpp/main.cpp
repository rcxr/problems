// https://omegaup.com/arena/problem/OMI-2016-All-Out

#include "bits/stdc++.h"

static int const NODO_INICIO = 0;
static int const NODO_FIN = 12;
static int const NODO_HEROES[4] = { 1, 2, 3, 4 };
static int const NODO_ATAQUES[7] = { 5, 6, 7, 8, 9, 10, 11 };
static int const NODOS_CANTIDAD = 13;
static int const HEROES_CANTIDAD = 4;
static int const TIPOS_CANTIDAD = 7;
static int const ENEMIGOS_MAX = 50000;

class Grafo {
public:
  Grafo(std::array<int, HEROES_CANTIDAD> const& capacidadesDeAtaques, std::array<int, TIPOS_CANTIDAD> const& tiposDeEnemigos, std::array<std::array<bool, TIPOS_CANTIDAD>, HEROES_CANTIDAD> const& tiposDeAtaques) {
    for (int i = 0; i < NODOS_CANTIDAD; ++i) {
      for (int j = 0; j < NODOS_CANTIDAD; ++j) {
        capacidades[i][j] = 0;
      }
    }
    for (int i = 0; i < HEROES_CANTIDAD; ++i) {
      capacidades[NODO_INICIO][i] = capacidadesDeAtaques[i];
    }
    for (int i = 0; i < TIPOS_CANTIDAD; ++i) {
      capacidades[i][NODO_FIN] = tiposDeEnemigos[i];
    }
    for (int i = 0; i < HEROES_CANTIDAD; ++i) {
      for (int j = 0; j < TIPOS_CANTIDAD; ++j) {
        if (tiposDeAtaques[i][j]) {
          capacidades[i][j] = ENEMIGOS_MAX;
        }
      }
    }
    std::vector<int> ruta = buscarRuta();
  }
private:
  int capacidades[NODOS_CANTIDAD][NODOS_CANTIDAD];
};

// N, F, H, A, E, L, O
int volverLetraIndice(char ataque) {
  switch (ataque) {
    case 'N': return 0;
    case 'F': return 1;
    case 'H': return 2;
    case 'A': return 3;
    case 'E': return 4;
    case 'L': return 5;
    case 'O': return 6;
  }
  // Esto nunca deberia pasar
  throw;
}

void procesarTiposDeAtaquesIndividual(std::array<bool, TIPOS_CANTIDAD>& tiposDeAtaquesIndividual, std::string const& tiposDeAtaquesIndividualTemporal) {
  tiposDeAtaquesIndividual.fill(false);
  for (int i = 0; i < tiposDeAtaquesIndividualTemporal.size(); ++i) {
    tiposDeAtaquesIndividual[volverLetraIndice(tiposDeAtaquesIndividualTemporal[i])] = true;
  }
}

int main() {
  int numeroEnemigos, costoPorAtaque;
  std::cin >> numeroEnemigos >> costoPorAtaque;

  std::array<std::array<bool, TIPOS_CANTIDAD>, HEROES_CANTIDAD> tiposDeAtaques;
  std::array<int, HEROES_CANTIDAD> capacidadesDeAtaques;
  for (int i = 0; i < HEROES_CANTIDAD; ++i) {
    std::string tiposDeAtaquesIndividualTemporal;
    int energiaIndividual;
    std::cin >> tiposDeAtaquesIndividualTemporal >> energiaIndividual;
    procesarTiposDeAtaquesIndividual(tiposDeAtaques[i], tiposDeAtaquesIndividualTemporal);
    capacidadesDeAtaques[i] = energiaIndividual / costoPorAtaque;
  }

  std::array<int, TIPOS_CANTIDAD> tiposDeEnemigos;
  tiposDeEnemigos.fill(0);
  for (int i = 0; i < numeroEnemigos; ++i) {
    char tipoDeEnemigo;
    std::cin >> tipoDeEnemigo;
    ++tiposDeEnemigos[volverLetraIndice(tipoDeEnemigo)];
  }

  return 0;
}
