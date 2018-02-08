// http://codeforces.com/contest/922/problem/C

#include <iostream>
#include <unordered_map>

int main() {
  long n, k;
  std::cin >> n >> k;
  ++n;

  for (long i = 2; i <= k; ++i) {
    if (n % i) {
      std::cout << "No";
      return 0;
    }
  }

  std::cout << "Yes";
  return 0;
}
