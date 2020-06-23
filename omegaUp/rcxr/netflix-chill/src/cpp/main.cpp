// https://omegaup.com/arena/problem/netflix-chill

#include "bits/stdc++.h"
#include <unordered_map>

void moveVertically(int offset) {
  while (offset < 0) {
    std::cout << "A";
    ++offset;
  }
  while (0 < offset) {
    std::cout << "a";
    --offset;
  }
}

void moveHorizontally(int offset) {
  while (offset < 0) {
    std::cout << "i";
    ++offset;
  }
  while (0 < offset) {
    std::cout << "d";
    --offset;
  }
}

void pressKey(int currentKey, int nextKey, int columns) {
  int currentRow = currentKey / columns;
  int nextRow = nextKey / columns;
  moveVertically(nextRow - currentRow);

  int currentCol = currentKey % columns;
  int nextCol = nextKey % columns;
  moveHorizontally(nextCol - currentCol);

  std::cout << "!";
}

int main() {
  int rows, columns;
  std::cin >> rows >> columns;
  std::cin >> std::ws;

  std::unordered_map<char, int> keyboard;
  for (int row = 0; row < rows; ++row) {
    std::string rowKeys;
    std::getline(std::cin, rowKeys);
    for (int col = 0; col < columns; ++col) {
      keyboard[::tolower(rowKeys.at(col))] = row * columns + col;
    }
  }

  std::string title;
  std::getline(std::cin, title);

  int currentKey = 0;
  for (char const &c : title) {
    if (keyboard.find(::tolower(c)) != keyboard.end()) {
      int nextKey = keyboard[::tolower(c)];
      pressKey(currentKey, nextKey, columns);
      currentKey = nextKey;
    }
  }

  return 0;
}
