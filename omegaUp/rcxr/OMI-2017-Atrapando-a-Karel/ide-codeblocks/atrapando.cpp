// https://omegaup.com/arena/problem/OMI-2017-Atrapando-a-Karel

#include "atrapando.h"

// int ponMuro(int f, int c, int d)

// Diferentes direcciones usadas en el programa
enum Direccion { ARRIBA = 2, ABAJO = 4, IZQUIERDA = 3, DERECHA = 1 };

// Representa una casilla en el tablero
class Casilla {
public:
  // Inicialmente las casillas no tienen ningun muro
  Casilla() : arriba(false), abajo(false), izquierda(false), derecha(false) {}

  void ponerMuro(Direccion d) {
    switch (d) {
    case ARRIBA:
      arriba = true;
      return;
    case ABAJO:
      abajo = true;
      return;
    case IZQUIERDA:
      izquierda = true;
      return;
    case DERECHA:
      derecha = true;
      return;
    }
  }

  bool tieneMuro(Direccion d) const {
    switch (d) {
    case ARRIBA:
      return arriba;
    case ABAJO:
      return abajo;
    case IZQUIERDA:
      return izquierda;
    case DERECHA:
      return derecha;
    }
  }

private:
  bool arriba;
  bool abajo;
  bool derecha;
  bool izquierda;
};

class Tablero {
public:
  // Para minimizar la cantidad de muros que se utilicen
  // nos vamos a concentrar solamente en el sub-tablero
  // de 9x9 e ignorar lo demas (a fin de cuentas solo
  // necesitamos 9x9 para encerrar a Karel)
  //
  // Offset se calcula con respecto a la region que no forma parte del
  // sub-tablero de 9x9. Se agrega uno al offset ya que las coordenadas
  // del tablero original empiezan en 1 y no en 0
  //
  // Karel inicialmente no esta rodeado
  //
  // Karel empieza en el centro del sub-tablero (fila = 4, columna = 4)
  Tablero(int n) : offset((n - 9) / 2 + 1), rodeado(false), kf(4), kc(4) {}

  bool estaKarelRodeado() const {
    return rodeado;
  }

  void atrapando() {
    // Primero hay que poner los 4 muros que garantizan que no se escape
    if (!subTablero[0][0].tieneMuro(IZQUIERDA)) {
      moverKarel(ponerMuro(0, 0, IZQUIERDA));
      return;
    }
    if (!subTablero[8][0].tieneMuro(IZQUIERDA)) {
      moverKarel(ponerMuro(8, 0, IZQUIERDA));
      return;
    }
    if (!subTablero[0][8].tieneMuro(DERECHA)) {
      moverKarel(ponerMuro(0, 8, DERECHA));
      return;
    }
    if (!subTablero[8][8].tieneMuro(DERECHA)) {
      moverKarel(ponerMuro(8, 8, DERECHA));
      return;
    }

    // Ahora hay que revisar si Karel esta a punto de escapar
    if (0 == kc && !subTablero[kf][kc].tieneMuro(IZQUIERDA)) {
      moverKarel(ponerMuro(kf, kc, IZQUIERDA));
      return;
    }
    if (8 == kc && !subTablero[kf][kc].tieneMuro(DERECHA)) {
      moverKarel(ponerMuro(kf, kc, DERECHA));
      return;
    }
    if (0 == kf && !subTablero[kf][kc].tieneMuro(ARRIBA)) {
      moverKarel(ponerMuro(kf, kc, ARRIBA));
      return;
    }
    if (8 == kf && !subTablero[kf][kc].tieneMuro(ABAJO)) {
      moverKarel(ponerMuro(kf, kc, ABAJO));
      return;
    }

    // Si no, simplemente tira cualquier cosa (OJO: esto no es optimo)
    if (!subTablero[kf][kc].tieneMuro(IZQUIERDA)) {
      moverKarel(ponerMuro(kf, kc, IZQUIERDA));
      return;
    }
    if (!subTablero[kf][kc].tieneMuro(DERECHA)) {
      moverKarel(ponerMuro(kf, kc, DERECHA));
      return;
    }
    if (!subTablero[kf][kc].tieneMuro(ARRIBA)) {
      moverKarel(ponerMuro(kf, kc, ARRIBA));
      return;
    }
    if (!subTablero[kf][kc].tieneMuro(ABAJO)) {
      moverKarel(ponerMuro(kf, kc, ABAJO));
      return;
    }
  }

private:
  int ponerMuro(int f, int c, Direccion d) {
    subTablero[f][c].ponerMuro(d);
    switch (d) {
    case IZQUIERDA:
      if (0 < c) {
        subTablero[f][c - 1].ponerMuro(DERECHA);
      }
      break;
    case DERECHA:
      if (c < 8) {
        subTablero[f][c + 1].ponerMuro(IZQUIERDA);
      }
      break;
    case ARRIBA:
      if (0 < f) {
        subTablero[f - 1][c].ponerMuro(ABAJO);
      }
      break;
    case ABAJO:
      if (f < 8) {
        subTablero[f + 1][c].ponerMuro(ARRIBA);
      }
      break;
    }
    return ponMuro(f + offset, c + offset, (int) d);
  }

  void moverKarel(int movimiento) {
    switch (movimiento) {
    case 0:
      rodeado = true;
      return;
    case 1:
      ++kc;
      return;
    case 2:
      --kf;
      return;
    case 3:
      --kc;
      return;
    case 4:
      ++kf;
      return;
    }
  }

  // Posicion de Karel
  int kf;
  int kc;

  // Esta Karel rodeado?
  bool rodeado;

  // Sub-tablero
  Casilla subTablero[9][9];

  // Offset usado para transformar coordenadas
  // del sub-tablero a coordenadas del tablero
  // original
  int offset;
};

void atrapando(int n) {
  Tablero tablero(n);
  while (!tablero.estaKarelRodeado()) {
    tablero.atrapando();
  }
}
