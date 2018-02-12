// https://www.hackerrank.com/challenges/30-bitwise-and

#include "bits/stdc++.h"

int flipLessSignificativeZero(int x) {
  int flag = 1;
  while (x & flag) {
    flag <<= 1;
  }
  return x | flag;
}

int findMax(int n, int k) {
  int test = k < n ? k - 1 : n - 1;
  while (test) {
    if (flipLessSignificativeZero(test) <= n) {
      return test;
    }
    --test;
  }
  return 0;
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, k;
    std::cin >> n >> k;
    std::cout << findMax(n, k) << std::endl;
  }
  return 0;
}
