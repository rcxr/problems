// http://codeforces.com/contest/922/problem/A

#include <iostream>

bool isPossible(unsigned originals, unsigned copies) {
  if (originals < 1) {
    return false;
  }

  if (0 < copies && 1 == originals) {
    return false;
  }

  if (0 == (originals + copies) % 2) {
    return false;
  }

  return originals <= copies + 1;
}

int main() {
  unsigned originals, copies;
  std::cin >> copies >> originals;
  std::cout << (isPossible(originals, copies) ? "Yes" : "No");
}
