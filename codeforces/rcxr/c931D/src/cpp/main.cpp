// http://codeforces.com/contest/931/problem/D

#include "bits/stdc++.h"
#include <unordered_set>

void copyLogs(std::unordered_set<int>& nextLog, std::unordered_set<int>& log) {
  for (auto& t : log) {
    auto temp = nextLog.find(t + 1);
    if (nextLog.end() == temp) {
      nextLog.insert(t + 1);
    } else {
      nextLog.erase(temp);
    }
  }
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> nextBranch(n);
  for (int i = 1; i < n; ++i) {
    int temp;
    std::cin >> temp;
    nextBranch[i] = temp - 1;
  }

  std::vector<std::unordered_set<int>> logs(n);
  for (auto& log : logs) {
    log.insert(0);
  }

  for (int i = n - 1; 0 < i; --i) {
    copyLogs(logs[nextBranch[i]], logs[i]);
  }

  std::cout << logs[0].size();

  return 0;
}
