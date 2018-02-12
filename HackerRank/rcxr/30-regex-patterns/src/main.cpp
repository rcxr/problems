// https://www.hackerrank.com/challenges/30-regex-patterns

#include "bits/stdc++.h"

std::vector<std::string> readNames(int n) {
  std::vector<std::string> names;
  for (int i = 0; i < n; ++i) {
    std::string name, email;
    std::cin >> name >> email;
    if (std::regex_match(email, std::regex(".*@gmail\\.com$"))) {
      names.push_back(name);
    }
  }
  return names;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<std::string> names = readNames(n);
  std::sort(names.begin(), names.end());

  for (std::string& name : names) {
    std::cout << name << std::endl;
  }
  return 0;
}
