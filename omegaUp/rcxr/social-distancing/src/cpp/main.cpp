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
    int dx = c->x() - x();
    int dy = c->y() - y();
    return dx * dx + dy * dy > SAFE_DISTANCE;
  }

  int x() const { return p[X]; }
  int y() const { return p[Y]; }
  int getGroupId() const { return groupId; }

private:
  const int id;
  const std::array<int, 2> p;
  int groupId;
  std::set<int> neighborsX;
  std::set<int> neighborsY;
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
    checkNeighbors();
    normalizeGroups();

    std::unordered_set<int> candidateGroups;
    for (auto m : marchantes) {
      if (m->x() <= 2) {
        candidateGroups.insert(m->getGroupId());
      }
    }

    for (auto m : marchantes) {
      if (m->x() >= w - 2) {
        if (candidateGroups.find(m->getGroupId()) != candidateGroups.end()) {
          return false;
        }
      }
    }

    return true;
  }

private:
  std::vector<Marchante *> marchantes;
  const int w;
  const int l;

  void populateNeighbors(int dimension) {}
  void checkNeighbors() {}
  void normalizeGroups() {}
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
