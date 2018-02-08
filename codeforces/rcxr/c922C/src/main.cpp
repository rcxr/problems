// http://codeforces.com/contest/922/problem/C

#include <iostream>

int main() {
  long long n, k;
  std::cin >> n >> k;

  bool valid = true;
  for (long long i = 2; i <= k; ++i) {
    if (0 != ((n + 1) % i)) {
      valid = false;
      break;
    }
  }

  std::cout << (valid ? "Yes" : "No");
  return 0;
}
