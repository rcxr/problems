// http://codeforces.com/contest/931/problem/0

#include <iostream>

int main() {
  long a, b;
  std::cin >> a >> b;

  long d = abs(a - b);
  long h = d / 2;

  long r = h * (h + 1);
  if (d % 2) {
    r += h + 1;
  }

  std::cout << r;
  return 0;
}
