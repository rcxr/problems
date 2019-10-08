// https://omegaup.com/arena/problem/tecnm-19-scoreboard

#include "bits/stdc++.h"

int main() {
  int n;
  std::cin >> n;

  std::unordered_map<std::string, std::unordered_set<int>> scores;

  for (int i = 0; i < n; ++i) {
    std::string name;
    std::cin >> name;
    int problem;
    std::cin >> problem;

    auto it = scores.find(name);
    if (it == scores.end()) {
      std::unordered_set<int> problems;
      scores.insert(std::make_pair(name, problems));
    }

    scores[name].insert(problem);
  }

  int max = 0;
  for (auto const &score : scores) {
    if (max < score.second.size()) {
      max = score.second.size();
    }
  }

  std::vector<std::string> winners;
  for (auto const &score : scores) {
    if (max == score.second.size()) {
      winners.push_back(score.first);
    }
  }

  std::sort(winners.begin(), winners.end());

  for (auto const &winner : winners) {
    std::cout << winner << ' ';
  }

  return 0;
}
