// https://omegaup.com/arena/problem/social-distancing

#include "bits/stdc++.h"

#define X 0
#define Y 1
#define SAFE_DISTANCE 16

class Marchante {
public:
  Marchante(int id, int x, int y) : id(id), groupId(id), p({x, y}) {
  }

  bool isSafe(const Marchante *c) const {
    int dx = c->p[X] - p[X];
    int dy = c->p[Y] - p[Y];
    return dx * dx + dy * dy > SAFE_DISTANCE;
  }

private:
  const int id;
  const std::array<int, 2> p;
  int groupId;
  std::set<int> neighbors0;
  std::set<int> neighbors1;
};

class Mercado {
public:
  Mercado(int w, int l) : w(w), l(l) {}

  ~Mercado() {
    for(auto m : marchantes) {
      delete m;
    }
    marchantes.clear();
  }

  void addMarchante(int id, int x, int y) {
    marchantes.push_back(new Marchante(id, x, y));
  }

  bool isSafe() {
    populateNeighbors(X);
    populateNeighbors(Y);
    return true;
  }
private:
  std::vector<Marchante *> marchantes;
  const int w;
  const int l;

  void populateNeighbors(int dimension) {}
};

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int m, w, l;
    std::cin >> m >> w >> l;

    Mercado mercado(w, l);

    for (int j = 0; j < m; ++j) {
      int x, y;
      std::cin >> x >> y;
      mercado.addMarchante(j, x, y);
    }

    std::cout << (mercado.isSafe() ? "SAFE" : "RISKY") << std::endl;
  }

  return 0;
}
