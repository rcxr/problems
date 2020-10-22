// https://omegaup.com/arena/problem/social-distancing
#include "bits/stdc++.h"
#define SAFE_DISTANCE 16

class Marchante {
public:
  Marchante(int id, int x, int y) : id(id), x(x), y(y), visited(false) {}

  static void calculateNeighbors(std::vector<Marchante *> marchantes) {
    std::vector<std::pair<int, int>> boundaries;
    for (auto m : marchantes) {
      boundaries.push_back(std::make_pair((m->x - 2) * 2, m->id));
      boundaries.push_back(std::make_pair((m->x + 2) * 2 + 1, m->id));
    }

    std::sort(boundaries.begin(), boundaries.end());

    std::set<int> candidates;
    for (const auto &b : boundaries) {
      if (b.first % 2 == 0) {
        Marchante *m1 = marchantes[b.second];
        for (auto c : candidates) {
          Marchante *m2 = marchantes[c];
          if (!m1->touches(m2)) {
            m1->neighbors.insert(m2);
            m2->neighbors.insert(m1);
          }
        }
        candidates.insert(b.second);
      } else {
        candidates.erase(b.second);
      }
    }
  }

  static bool areSafe(std::vector<Marchante *> marchantes, int w) {
    std::vector<Marchante *> risky;
    for (auto m : marchantes) {
      if (m->x <= 2) { risky.push_back(m); }
    }

    for (auto r : risky) {
      if (!r->isSafe(w)) { return false; }
    }

    return true;
  }

private:
  const int id, x, y;
  bool visited;
  std::set<Marchante *> neighbors;

  bool isSafe(int w) {
    if (visited) { return true; }
    if (x >= w - 2) { return false; }

    visited = true;

    for (auto n : neighbors) {
      if (!n->isSafe(w)) { return false; }
    }

    return true;
  }

  bool touches(const Marchante *c) const {
    int dx = c->x - x;
    int dy = c->y - y;
    return dx * dx + dy * dy > SAFE_DISTANCE;
  }
};

class Mercado {
public:
  Mercado(int w) : w(w) {}

  ~Mercado() {
    for(auto m : marchantes) { delete m; }
    marchantes.clear();
  }

  void addMarchante(int id, int x, int y) {
    marchantes.push_back(new Marchante(id, x, y));
  }

  bool isSafe() {
    Marchante::calculateNeighbors(marchantes);
    return Marchante::areSafe(marchantes, w);
  }

private:
  const int w;
  std::vector<Marchante *> marchantes;
};

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int m, w, l;
    std::cin >> m >> w >> l;

    Mercado mercado(w);
    for (int j = 0; j < m; ++j) {
      int x, y;
      std::cin >> x >> y;
      mercado.addMarchante(j, x, y);
    }

    std::cout << (mercado.isSafe() ? "SAFE" : "RISKY") << std::endl;
  }

  return 0;
}
