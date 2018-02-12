// https://www.hackerrank.com/challenges/ctci-making-anagrams

#include "bits/stdc++.h"

int calculateAnagramDelta(std::string const& a, std::string const& b) {
  std::vector<int> counts(26, 0);
  for (int i = 0; i < a.length(); ++i) {
    ++counts[a[i] - 'a'];
  }
  for (int i = 0; i < b.length(); ++i) {
    --counts[b[i] - 'a'];
  }
  int result = 0;
  for (int& count : counts) {
    result += abs(count);
  }
  return result;
}

int main() {
  std::string a, b;
  std::cin >> a >> b;
  std::cout << calculateAnagramDelta(a, b);
  return 0;
}
