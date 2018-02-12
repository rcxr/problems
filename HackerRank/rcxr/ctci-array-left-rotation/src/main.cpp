// https://www.hackerrank.com/challenges/ctci-array-left-rotation

#include "bits/stdc++.h"

int gcd(int a, int b) {
  while (b) {
    auto t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int calculateNextIndex(int index, int shift, int size) {
  int nextIndex = (index - shift) % size;
  return nextIndex < 0 ? nextIndex + size : nextIndex;
}

void leftRotate(std::vector<int>& array, int shift) {
  int d = gcd(array.size(), shift);
  for (int i = 0; i < d; ++i) {
    int index = i;
    int temp = array[index];
    for (int j = 0; j < array.size() / d; ++j) {
      int nextIndex = calculateNextIndex(index, shift, array.size());
      int nextTemp = array[nextIndex];

      array[nextIndex] = temp;

      index = nextIndex;
      temp = nextTemp;
    }
  }
}

void printArray(std::vector<int> const& array) {
  for (int const& value : array) {
    std::cout << value << " ";
  }
}

std::vector<int> readArray(int size) {
  std::vector<int> array(size);
  for (int i = 0; i < size; ++i) {
    std::cin >> array[i];
  }
  return array;
}

int main() {
  long size, shift;
  std::cin >> size >> shift;
  std::vector<int> array = readArray(size);
  leftRotate(array, shift);
  printArray(array);
  return 0;
}
