// https://www.hackerrank.com/contests/w36/challenges/cut-a-strip

#include "bits/stdc++.h"

class Container {
public:
  Container(int size) : next(0), array(size) {}

  void push(int value) {
    array[next] = value;
    next = index(next + 1);
  }

  int min() const {
    auto min = INT_MAX;
    auto sum = 0;
    for (auto i = 1; i <= array.size(); ++i) {
      sum += value(next - i);
      min = sum < min ? sum : min;
    }
    return min;
  }

private:
  int next;
  std::vector<int> array;

  int value(int i) const {
    return array[index(i)];
  }

  int index(int i) const {
    return (i + array.size()) % array.size();
  }
};

std::vector<std::vector<int>> readGrid(int rows, int cols) {
  std::vector<std::vector<int>> grid(rows);
  for (auto row = 0; row < rows; ++row) {
    for (auto col = 0; col < cols; ++col) {
      int temp;
      std::cin >> temp;
      grid[row].push_back(temp);
    }
  }
  return grid;
}

int sumGrid(std::vector<std::vector<int>> const& grid, int rows, int cols) {
  auto sum = 0;
  for (auto row = 0; row < rows; ++row) {
    for (auto col = 0; col < cols; ++col) {
      sum += grid[row][col];
    }
  }
  return sum;
}

int findMinStripPartial(std::vector<int> const& array, int k) {
  Container container(k);
  auto min = INT_MAX;
  for (auto value : array) {
    container.push(value);
    auto partialMin = container.min();
    min = partialMin < min ? partialMin : min;
  }
  return min;
}

std::vector<int> extractRow(std::vector<std::vector<int>> const& grid, int row, int cols) {
  std::vector<int> result(cols);
  for (auto col = 0; col < cols; ++col) {
    result[col] = grid[row][col];
  }
  return result;
}

std::vector<int> extractCol(std::vector<std::vector<int>> const& grid, int col, int rows) {
  std::vector<int> result(rows);
  for (auto row = 0; row < rows; ++row) {
    result[row] = grid[row][col];
  }
  return result;
}

int findMinStrip(std::vector<std::vector<int>> const& grid, int rows, int cols, int k) {
  auto min = INT_MAX;
  for (auto col = 0; col < cols; ++col) {
    auto partialMin = findMinStripPartial(extractCol(grid, col, rows), k);
    min = partialMin < min ? partialMin : min;
  }
  for (auto row = 0; row < rows; ++row) {
    auto partialMin = findMinStripPartial(extractRow(grid, row, cols), k);
    min = partialMin < min ? partialMin : min;
  }
  return min;
}

int main() {
  int rows, cols, k;
  std::cin >> rows >> cols >> k;
  auto grid = readGrid(rows, cols);
  std::cout << sumGrid(grid, rows, cols) - findMinStrip(grid, rows, cols, k);
  return 0;
}
