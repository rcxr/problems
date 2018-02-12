// https://www.hackerrank.com/challenges/30-sorting

#include "bits/stdc++.h"
#include <unordered_map>

std::vector<int> readArray(int n) {
  std::vector<int> array(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> array[i];
  }
  return array;
}

int countSwaps(std::vector<int> array) {
  int swaps = 0;

  for (unsigned i = 0u; i < array.size(); ++i) {
    for (unsigned j = 0u; j + 1< array.size(); ++j) {
      if (array[j + 1] < array[j]) {
        std::swap(array[j], array[j + 1]);
        ++swaps;
      }
    }
  }

  return swaps;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> array = readArray(n);
  std::cout << "Array is sorted in " << countSwaps(array) << " swaps." << std::endl;
  std::cout << "First Element: " << *min_element(array.begin(), array.end()) << std::endl;
  std::cout << "Last Element: " << *max_element(array.begin(), array.end()) << std::endl;
  return 0;
}
