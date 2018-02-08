// https://www.hackerrank.com/challenges/divisible-sum-pairs

#include <vector>
#include <iostream>

using namespace std;

int divisibleSumPairs(int const k, vector<int> ar) {
  vector<int> mods(k, 0);
  for (auto a : ar) {
    ++mods[(a % k + k) % k];
  }
  auto total = 0;
  if (1 < mods[0]) {
    total += mods[0] * (mods[0] - 1) / 2;
  }
  if (k % 2 == 0 && 1 < mods[k / 2]) {
    total += mods[k / 2] * (mods[k / 2] - 1) / 2;
  }
  for (auto i = 1; i <= (k - 1) / 2; ++i) {
    total += mods[i] * mods[k - i];
  }
  return total;
}

int main() {
  int n;
  int k;
  cin >> n >> k;
  vector<int> ar(n);
  for (auto i = 0; i < n; ++i) {
     cin >> ar[i];
  }
  cout << divisibleSumPairs(k, ar) << endl;
  return 0;
}
