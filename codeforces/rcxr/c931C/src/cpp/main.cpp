// http://codeforces.com/contest/931/problem/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> values(n);
  int min = INT_MAX;
  int max = INT_MIN;
  for (int i = 0; i < n; ++i) {
    int t;
    std::cin >> t;
    min = t < min ? t : min;
    max = max < t ? t : max;
    values[i] = t;
  }

  if (min == max) {
    std::cout << n << std::endl;
    for (int i = 0; i < n; ++i) {
      std::cout << min << " ";
    }
    return 0;
  }

  int minCount = 0;
  int maxCount = 0;
  for (int& value : values) {
    if (min == value) {
      ++minCount;
    }
    if (max == value) {
      ++maxCount;
    }
  }

  if (min + 1 == max) {
    std::cout << n << std::endl;
    for (int i = 0; i < minCount; ++i) {
      std::cout << min << " ";
    }
    for (int i = minCount; i < n; ++i) {
      std::cout << max << " ";
    }
    return 0;
  }

  int middleCount = n - minCount - maxCount;

  int toBottom = middleCount / 2;
  int toTop = std::min(minCount, maxCount);

  int r = n - std::max(toTop, toBottom) * 2;

  std::cout << r << std::endl;

  if (toTop < toBottom) {
    maxCount += toBottom;
    minCount += toBottom;
    middleCount -= toBottom * 2;
  } else {
    maxCount -= toTop;
    minCount -= toTop;
    middleCount += toTop * 2;
  }

  for (int i = 0; i < minCount; ++i) {
    std::cout << min << " ";
  }
  for (int i = 0; i < middleCount; ++i) {
    std::cout << min + 1 << " ";
  }
  for (int i = 0; i < maxCount; ++i) {
    std::cout << max << " ";
  }

  return 0;
}
