// http://codeforces.com/contest/922/problem/C

#include <iostream>
#include <unordered_map>

void process(std::unordered_map<unsigned long, unsigned long>& primes, unsigned long n) {
  for (auto prime : primes) {
    for (unsigned long i = 0; i < prime.second; ++i) {
      if (n % prime.first) {
        break;
      }
      n /= prime.first;
    }
  }

  if (1 < n) {
    if (primes.end() == primes.find(n)) {
      primes[n] = 0;
    }
    ++primes[n];
  }
}

int main() {
  unsigned long n, k;
  std::cin >> n >> k;

  std::unordered_map<unsigned long, unsigned long> primes;
  for (unsigned long i = 2; i <= k; ++i) {
    process(primes, i);
  }

  n++;

  for (auto prime : primes) {
    for (unsigned long i = 0; i < prime.second; ++i) {
      if (n % prime.first) {
        std::cout << "No";
        return 0;
      }
      n /= prime.first;
    }
  }

  std::cout << "Yes";
  return 0;
}
