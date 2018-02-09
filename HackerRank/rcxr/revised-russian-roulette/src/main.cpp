// https://www.hackerrank.com/contests/w36/challenges/revised-russian-roulette

#include "bits/stdc++.h"

int main() {
  unsigned n;
  std::cin >> n;

  auto min = 0u;
  auto max = 0u;
  bool previous = false;
  while (n--) {
    bool door;
    std::cin >> door;
    if (door) {
      ++max;
      if (previous) {
        previous = false;
      } else {
        ++min;
        previous = true;
      }
    } else {
      previous = false;
    }
  }
  std::cout << min << " " << max;
  return 0;
}
