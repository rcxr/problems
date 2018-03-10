// http://codeforces.com/contest/931/problem/D

#include "bits/stdc++.h"
#include <unordered_map>

int main() {
  // Reading number of branches
  int n;
  std::cin >> n;

  // This stores the distance to the root
  std::vector<int> depths(n);
  // This counts the instances of the different depths
  std::unordered_map<int, int> depthCounts;

  // It's known that the depth of the first branch is zero
  depths[0] = 0;
  // Set the counter for the zero depth to 1
  depthCounts[0] = 1;

  // Read the tree structure
  for (int i = 1; i < n; ++i) {
    int temp;
    std::cin >> temp;
    // The current branch will have its apples move to this other branch (which we are calling next branch)
    int nextBranch = temp - 1;
    // The depth of this branch will be 1 more than the next branch
    depths[i] = depths[nextBranch] + 1;
    // Increase the counter for this depth
    if (depthCounts.end() == depthCounts.find(depths[i])) {
      depthCounts[depths[i]] = 1;
    } else {
      ++depthCounts[depths[i]];
    }
  }

  int result = 0;
  // Count how many depths have an odd number of occurrences
  for (auto& depthCount : depthCounts) {
    if (depthCount.second % 2) {
      ++result;
    }
  }

  std::cout << result;

  return 0;
}
