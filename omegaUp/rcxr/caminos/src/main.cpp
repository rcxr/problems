// https://omegaup.com/arena/problem/caminos

#include "bits/stdc++.h"

int main() {
  int a, b;
  std::cin >> a >> b;
  int ab = a + b;

  long r = 1;
  for (int i = 1; i <= b; ++i) {
    r = r * ab / i;
    --ab;
  }
  std::cout << r;
  return 0;
}
