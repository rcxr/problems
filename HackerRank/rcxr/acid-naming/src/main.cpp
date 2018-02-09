// https://www.hackerrank.com/contests/w36/challenges/acid-naming

#include "bits/stdc++.h"

std::string determineAcid(std::string const& word) {
  if (!std::regex_match(word, std::regex(".*ic$"))) {
    return "not an acid";
  }

  if (!std::regex_match(word, std::regex("^hydro.*"))) {
    return "polyatomic acid";
  }

  return "non-metal acid";
}

int main() {
  unsigned n;
  std::cin >> n;
  while (n--) {
    std::string word;
    std::cin >> word;
    std::cout << determineAcid(word) << std::endl;
  }
  return 0;
}
