// http://codeforces.com/contest/922/problem/C

#include <iostream>
#include <unordered_map>

int pow(long base, long exp) {
  long result = 1;
  while (exp != 0) {
    if ((exp & 1) == 1) {
      result *= base;
    }
    exp >>= 1;
    base *= base;
  }
  return result;
}

void process(std::unordered_map<long, long>& primes, long i) {
  for (auto prime : primes) {
    for (auto i = 0; i < prime.second && 0 == i % prime.first; ++i) {
      i /= prime.first;
    }
  }
  if (1 < i) {
    if (primes.end() == primes.find(i)) {
      primes[i] = 0;
    }
    ++primes[i];
  }
}

long gcd(long a, long b) {
  while (b) {
    auto t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main() {
  long n, k;
  std::cin >> n >> k;

  std::unordered_map<long, long> primes;
  for (long i = 2; i <= k; ++i) {
    process(primes, i);
  }

  n++;

  for (auto prime : primes) {
    auto m = n;
    for (auto i = 0; i < prime.second && 0 == m % prime.first; ++i) {
      m /= prime.first;
    }
    if (1 < m) {
      std::cout << "No";
      return 0;
    }
  }

  std::cout << "Yes";
  return 0;
}
