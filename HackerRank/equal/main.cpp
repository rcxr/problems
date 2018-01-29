#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

int minSteps(int delta, unordered_map<int, int>& cache) {
  if (delta < 0) {
    return INT_MAX;
  }
  if (cache.end() != cache.find(delta)) {
    return cache[delta];
  }
  vector<int> results = {
    minSteps(delta - 1, cache),
    minSteps(delta - 3, cache),
    minSteps(delta - 5, cache)
  };
  cache[delta] = *min_element(results.begin(), results.begin()) + 1;
  return cache[delta];
}

int equal(vector<int> const& arr, unordered_map<int, int>& cache) {
  auto min = *min_element(arr.begin(), arr.end());
  auto result = 0;
  for (auto v : arr) {
    result += minSteps(v - min, cache);
  }
  return result;
}

int main() {
  unordered_map<int, int> cache;
  cache[0] = 0;
  cache[1] = cache[3] = cache[5] = 1;

  int t;
  cin >> t;
  while (0 < t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    while (0 < n--) {
      cin >> arr[n];
    }
    cout << equal(arr, cache) << endl;
  }

  return 0;
}
