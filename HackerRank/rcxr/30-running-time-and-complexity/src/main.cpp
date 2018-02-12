// https://www.hackerrank.com/challenges/30-running-time-and-complexity

#include "bits/stdc++.h"

bool isPrime(int x) {
  // Using x is prime iff -x is prime
  x = abs(x);
  if (x < 2) {
    return false;
  }
  for (int i = 2; i * i <= x; ++i) {
    if (0 == x % i) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    std::cout << (isPrime(x) ? "Prime" : "Not prime") << std::endl;
  }
  return 0;
}
