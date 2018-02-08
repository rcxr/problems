// http://codeforces.com/contest/922/problem/B

#include <iostream>

int countXor(unsigned n) {
  auto count = 0u;
  for (auto a = 2u; a < n; ++a) {
    for (auto c = n; a < c; --c) {
      auto b = a ^ c;
      if (a < b && b < c && a < b + c && c < a + b) {
        ++count;
      }
    }
  }
  return count;
}

int main() {
  unsigned n;
  std::cin >> n;
  std::cout << countXor(n);
}
