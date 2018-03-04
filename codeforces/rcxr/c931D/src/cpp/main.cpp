// http://codeforces.com/contest/931/problem/D

#include "bits/stdc++.h"

int main() {
  int n;
  std::cin >> n;

  std::vector<int> next(n);
  std::map<int, bool> apples;
  apples[0] = true;
  for (int i = 1; i < n; ++i) {
    int t;
    std::cin >> t;
    next[i] = t - 1;
    apples[i] = true;
  }

  std::vector<int> distance;
  distance.push_back(1);
  int maxDistance = INT_MIN;
  for (int i = 1; i < n; ++i) {
    int d = distance[next[i]] + 1;
    maxDistance = maxDistance < d ? d : maxDistance;
    distance.push_back(d);
  }

  int appleCount = 0;
  for (int i = 0; i < maxDistance; ++i) {
    auto temp1 = apples.find(0);
    if (apples.end() != temp1 && temp1->second) {
      ++appleCount;
    }

    std::map<int, bool> nextApples;
    for (auto& apple : apples) {
      if (apple.first && apple.second) {
        int nextApple = next[apple.first];
        auto temp = nextApples.find(nextApple);
        if (nextApples.end() == temp) {
          nextApples[nextApple] = true;
        } else {
          nextApples[nextApple] = !temp->second;
        }
      }
    }

    apples = nextApples;
  }
  std::cout << appleCount;
  return 0;
}
