// https://omegaup.com/arena/problem/social-distancing

#include "bits/stdc++.h"

#define X 0
#define Y 1
#define SAFE_DISTANCE 16

class Marchante {
public:
  Marchante(int id, int x, int y) : id(id), groupId(id), p({x, y}) {
  }

  static void populateNeighbors(std::vector<Marchante *> marchantes, int d) {
    std::vector<std::pair<int, int>> boundaries;
    for (auto m : marchantes) {
      boundaries.push_back(std::make_pair((m->p[d] - 2) * 2, m->id));
      boundaries.push_back(std::make_pair((m->p[d] + 2) * 2 + 1, m->id));
    }

    std::sort(boundaries.begin(), boundaries.end());

    std::set<int> active;
    for (const auto &b : boundaries) {
      if (b.first % 2 == 0) {
        for (auto a : active) {
          marchantes[a]->neighbors[d].insert(b.second);
        }
        marchantes[b.second]->neighbors[d] = active;
        active.insert(b.second);
      } else {
        active.erase(b.second);
      }
    }
  }

  static void checkNeighbors(std::vector<Marchante *> marchantes) {
    for (auto m : marchantes) {
      std::set<int> candidates;
      set_intersection(
        m->neighborsX().begin(),
        m->neighborsX().end(),
        m->neighborsY().begin(),
        m->neighborsY().end(),
        std::inserter(candidates, candidates.begin()));

      for (auto c : candidates) {
        Marchante *n = marchantes[c];
        if (!m->isSafe(n)) {
          int groupId = std::min(m->groupId, n->groupId);
          m->groupId = groupId;
          n->groupId = groupId;
        }
      }
    }
  }

  static void normalizeGroups(std::vector<Marchante *> marchantes) {
    // TODO: optimize with DP.
    for (auto m : marchantes) {
      m->groupId = findLeadGroup(marchantes, m->groupId);
    }
  }

  static bool areSafe(std::vector<Marchante *> marchantes, int w) {
    std::set<int> candidateGroups;
    for (auto m : marchantes) {
      if (m->x() <= 2) {
        candidateGroups.insert(m->groupId);
      }
    }

    for (auto m : marchantes) {
      if (m->x() >= w - 2) {
        if (candidateGroups.find(m->groupId) != candidateGroups.end()) {
          return false;
        }
      }
    }

    return true;
  }

private:
  const int id;
  int groupId;

  const std::array<int, 2> p;
  std::array<std::set<int>, 2> neighbors;

  const std::set<int> &neighborsX() const {
    return neighbors[X];
  }
  const std::set<int> &neighborsY() const {
    return neighbors[Y];
  }

  int x() const { return p[X]; }
  int y() const { return p[Y]; }

  bool isSafe(const Marchante *c) const {
    int dx = c->x() - x();
    int dy = c->y() - y();
    return dx * dx + dy * dy > SAFE_DISTANCE;
  }

  static int findLeadGroup(std::vector<Marchante *> marchantes, int groupId) {
    while (groupId != marchantes[groupId]->groupId) {
      groupId = marchantes[groupId]->groupId;
    }
    return groupId;
  }
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
    Marchante::populateNeighbors(marchantes, X);
    Marchante::populateNeighbors(marchantes, Y);
    Marchante::checkNeighbors(marchantes);
    Marchante::normalizeGroups(marchantes);
    return Marchante::areSafe(marchantes, w);
  }

private:
  std::vector<Marchante *> marchantes;
  const int w;
  const int l;
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
