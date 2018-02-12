// https://www.hackerrank.com/challenges/30-binary-trees

#include "bits/stdc++.h"

class Node {
public:
  explicit Node(int value) : left(nullptr), right(nullptr), value(value) {}
  ~Node() {
    if (nullptr != left) { delete left; }
    if (nullptr != right) { delete right; }
  }

  void insert(int value) {
    if (this->value < value) {
      if (nullptr == left) {
        left = new Node(value);
      } else {
        left->insert(value);
      }
    } else if (value < this->value) {
      if (nullptr == right) {
        right = new Node(value);
      } else {
        right->insert(value);
      }
    }
  }

  int height() const {
    int leftHeight = nullptr == left ? 0 : left->height();
    int rightHeight = nullptr == right ? 0 : right->height();
    return (leftHeight < rightHeight ? rightHeight : leftHeight) + 1;
  }

private:
  Node* left;
  Node* right;
  int const value;
};

int main() {
  int n;
  std::cin >> n;

  if (0 == n) {
    std::cout << 0;
    return 0;
  }

  int value;
  std::cin >> value;

  Node tree(value);

  for (int i = 1; i < n; ++i) {
    std::cin >> value;
    tree.insert(value);
  }

  std::cout << tree.height() - 1;
  return 0;
}
