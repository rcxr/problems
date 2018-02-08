// https://www.hackerrank.com/challenges/equal

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int minSteps(int delta, unordered_map<int, int>& cache) {
  if (cache.end() != cache.find(delta)) {
    return cache[delta];
  }

  vector<int> results;
  if (5 < delta) {
    results.push_back(minSteps(delta - 5, cache));
  }
  if (2 < delta) {
    results.push_back(minSteps(delta - 2, cache));
  }
  results.push_back(minSteps(delta - 1, cache));

  cache[delta] = *min_element(results.begin(), results.end()) + 1;
  return cache[delta];
}

int equal(vector<int> const& choco, unordered_map<int, int>& cache, int offset) {
  auto min = *min_element(choco.begin(), choco.end());
  auto result = 0;
  for (auto c : choco) {
    result += minSteps(c - min + offset, cache);
  }
  return result;
}

int equal(vector<int> const& choco, unordered_map<int, int>& cache) {
  vector<int > results = {
    equal(choco, cache, 0),
    equal(choco, cache, 1),
    equal(choco, cache, 2),
    equal(choco, cache, 3),
    equal(choco, cache, 4)
  };
  return *min_element(results.begin(), results.end());
}

int main() {
  unordered_map<int, int> cache;
  cache[0] = 0;
  cache[1] = cache[2] = cache[5] = 1;

  int tests, n;
  cin >> tests;
  while (0 < tests--) {
    cin >> n;
    vector<int> choco(n);
    while (0 < n--) {
      cin >> choco[n];
    }
    cout << equal(choco, cache) << endl;
  }

  return 0;
}
