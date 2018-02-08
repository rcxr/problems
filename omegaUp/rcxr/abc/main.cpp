// https://omegaup.com/arena/problem/abc

#include <bits/stdc++.h>

int lbs(unsigned num) {
    unsigned mask = 1;
    for (int cnt = 0; ++cnt <= 32; mask <<= 1) {
        if (num & mask) {
            return cnt;
        }
    }
    return 0;
}

int main() {
  std::vector<int> abc;
  int i;
  std::cin >> i; abc.push_back(i);
  std::cin >> i; abc.push_back(i);
  std::cin >> i; abc.push_back(i);

  std::sort(abc.begin(), abc.end());

  char c;
  std::cin >> c; std::cout << abc[c - 'A'] << " ";
  std::cin >> c; std::cout << abc[c - 'A'] << " ";
  std::cin >> c; std::cout << abc[c - 'A'] << " ";

  return 0;
}
