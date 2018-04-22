// https://omegaup.com/arena/problem/itp18-direcciones

#include "bits/stdc++.h"

void advance(int& row, int& col, int orientation) {
  switch (orientation) {
    case 0:
      ++col;
      break;
    case 1:
      ++row;
      break;
    case 2:
      --col;
      break;
    case 3:
      --row;
      break;
    default:
      throw;
  }
}

int followAdvice(int orientation, int advice) {
  switch (advice) {
    case 0:
      return orientation;
    case 1:
      return (orientation + 1) % 4;
    case 2:
      return (orientation + 3) % 4;
    case 3:
      return (orientation + 2) % 4;
  }
  throw;
}

bool isTec(int row, int col, int tecRow, int tecCol) {
  return row == tecRow && col == tecCol;
}

bool inBounds(int row, int col, int rows, int cols) {
  return 0 <= row && 0 <= col && row < rows && col < cols;
}

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> advices;
  for (int i = 0; i < n; ++i) {
    std::vector<int> row;
    for (int j = 0; j < m; ++j) {
      int v;
      std::cin >> v;
      row.push_back(v);
    }
    advices.emplace_back(row);
  }

  int row = 0;
  int col = 0;
  int orientation = 0;
  while (!isTec(row, col, n - 1, m - 1) && inBounds(row, col, n, m)) {
    orientation = followAdvice(orientation, advices[row][col]);
    advance(row, col, orientation);
  }

  std::cout << (isTec(row, col, n - 1, m - 1) ? "llegaste" : "te perdiste");

  return 0;
}
