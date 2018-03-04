// http://codeforces.com/contest/931/problem/B

#include <iostream>
#include <cmath>

int calculateDepth(int n, int a, int b, int d) {
  int h = n / 2;
  bool aLeft = a < h;
  bool bLeft = b < h;
  if (aLeft ^ bLeft) {
    return d;
  }
  return calculateDepth(h, a % h, b % h, d + 1);
}

int main() {
  int n, a, b;
  std::cin >> n >> a >> b;

  int pow = log2(n);

  int depth = calculateDepth(n, a - 1, b - 1, 0);

  if (depth) {
    std::cout << (pow - depth);
  } else {
    std::cout << "Final!";
  }

  return 0;
}
