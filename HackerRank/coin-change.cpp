#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

long getWays(long n, vector<long> const& coins, vector<unordered_map<long, long>>& cache, long level) {
  if (n < 0) {
    return 0;
  }
  if (cache[level - 1].end() != cache[level - 1].find(n)) {
    return cache[level - 1][n];
  }
  long result = 0;
  for (auto i = 0; i < level; ++i) {
    result += getWays(n - coins[i], coins, cache, i + 1);
  }
  cache[level - 1][n] = result;
  return result;
}

long getWays(long n, vector<long> const& coins) {
  vector<unordered_map<long, long>> cache(coins.size());
  for (auto i = 0; i < coins.size(); ++i) {
    cache[i][0] = 1;
  }
  return getWays(n, coins, cache, coins.size());
}

int main() {
  int n;
  int m;
  cin >> n >> m;
  vector<long> coins(m);
  for(auto i = 0; i < m; ++i) {
    cin >> coins[i];
  }
  sort(coins.begin(), coins.end());
  cout << getWays(n, coins);
  return 0;
}
