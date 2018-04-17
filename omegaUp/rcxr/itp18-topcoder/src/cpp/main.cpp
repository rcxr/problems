// https://omegaup.com/arena/problem/itp18-examen

#include "bits/stdc++.h"

int calculateUtility(std::vector<int> const & costs, std::vector<int> const & utilities, int set) {
  int utility = 0;
  int capacity = 180;
  int i = 0;
  while (set) {
    if (set & 1) {
      utility += utilities[i];
      capacity -= costs[i];
    }
    ++i;
    set = set >> 1;
  }
  return capacity < 0 ? 0 : utility;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> costs;
  std::vector<int> utilities;

  int pow2 = 1;
  for (int i = 0; i < n; ++i) {
    int cost, utility;
    std::cin >> cost >> utility;
    costs.push_back(cost);
    utilities.push_back(utility);
    pow2 = pow2 << 1;
  }

  int maxUtility = 0;
  for (int i = 0; i < pow2; ++i) {
    int utility = calculateUtility(costs, utilities, i);
    maxUtility = maxUtility < utility ? utility : maxUtility;
  }

  std::cout << maxUtility;

  return 0;
}
