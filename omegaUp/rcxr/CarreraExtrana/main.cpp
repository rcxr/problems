// https://omegaup.com/arena/problem/CarreraExtrana

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::unordered_map<int, int> decompose(int a) {
  std::unordered_map<int, int> canonical;
  while (0 == a % 2) {
    if (canonical.end() == canonical.find(2)) {
      canonical[2] = 0;
    }
    ++canonical[2];
    a = a / 2;
  }
  auto p = 3;
  while (p * p <= a) {
    while (0 == a % p) {
      if (canonical.end() == canonical.find(p)) {
        canonical[p] = 0;
      }
      ++canonical[p];
      a = a / p;
    }
    p += 2;
  }
  if (1 < a) {
    canonical[a] = 1;
  }
  return canonical;
}

std::vector<int> divisors(int const a) {
  std::vector<int> ds;

  std::vector<int> primes;
  std::vector<int> elevatedPrimes;
  std::vector<int> currExp;
  std::vector<int> maxExp;
  auto canonical = decompose(a);
  for (auto& pair : canonical) {
    primes.push_back(pair.first);
    elevatedPrimes.push_back(1);
    currExp.push_back(0);
    maxExp.push_back(pair.second);
    if (!pair.second) {
      throw;
    }
  }
  unsigned expIndex;
  do {
    auto d = 1;
    for (auto elevatedPrime : elevatedPrimes) {
      d *= elevatedPrime;
    }
    ds.push_back(d);
    for (expIndex = 0; expIndex < currExp.size() && currExp[expIndex] >= maxExp[expIndex]; ++expIndex) {
      currExp[expIndex] = 0;
      elevatedPrimes[expIndex] = 1;
    }
    if (expIndex < currExp.size()) {
      ++currExp[expIndex];
      elevatedPrimes[expIndex] *= primes[expIndex];
    }
  } while (expIndex < currExp.size());
  std::sort(ds.rbegin(), ds.rend());
  return ds;
}

int dp(int const goal, std::unordered_map<int, int>& map) {
  auto best = goal - 1;

  for (auto d : divisors(goal)) {
    if (d == goal) {
      continue;
    }
    if (map.end() == map.find(goal - d)) {
      map[goal - d] = dp(goal - d, map);
    }
    const auto curr = map[goal - d] + 1;
    if (curr < best) {
      best = curr;
    }
  }

  map[goal] = best;
  return best;
}

int main() {
  std::unordered_map<int, int> map;
  map[1] = 0;
  map[2] = 1;
  map[3] = 2;
  map[4] = 2;
  int a, b;
  std::cin >> a >> b;
  std::cout << dp(a, map) << " " << dp(b, map) << std::endl;
}
