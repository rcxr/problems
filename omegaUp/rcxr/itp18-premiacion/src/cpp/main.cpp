// https://omegaup.com/arena/problem/itp18-premiacion

#include "bits/stdc++.h"
#include <unordered_map>

int main() {
  int n;
  std::cin >> n;

  std::unordered_map<std::string, std::string> map;

  std::string c, p;
  for (int i = 0; i < n; ++i) {
    std::cin >> c >> p;
    map[p] = c;
  }

  p = "null";
  for (int i = 0; i < n; ++i) {
    p = map[p];
    std::cout << p << ' ';
  }

  return 0;
}
