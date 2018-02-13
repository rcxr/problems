// https://www.hackerrank.com/contests/projecteuler/challenges/euler001

#include "bits/stdc++.h"

long sumMultiplesOfX(long n, long x) {
  n /= x;
  return x * n * (n + 1) / 2;
}

long sumMultiplesOf3And5(long n) {
  return sumMultiplesOfX(n, 3) + sumMultiplesOfX(n, 5) - sumMultiplesOfX(n, 15);
}

int main() {
  int t;
  std::cin >> t;

  for (int i = 0; i < t; ++i) {
    long n;
    std::cin >> n;
    std::cout << sumMultiplesOf3And5(n - 1) << std::endl;
  }
  return 0;
}
