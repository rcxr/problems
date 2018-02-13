// https://www.hackerrank.com/challenges/ctci-balanced-brackets

#include "bits/stdc++.h"

enum BracesType { PARENTHESIS, CURLY, SQUARE };

bool attemptPop(std::stack<BracesType>& openBraces, BracesType type) {
  if (openBraces.empty()) {
    return false;
  }
  if (type != openBraces.top()) {
    return false;
  }
  openBraces.pop();
  return true;
}

bool isBalanced(std::string const& equation) {
  std::stack<BracesType> openBraces;
  for (unsigned i = 0u; i < equation.length(); ++i) {
    switch(equation[i]) {
      case '(':
        openBraces.push(BracesType::PARENTHESIS); break;
      case ')':
        if (!attemptPop(openBraces, BracesType::PARENTHESIS)) {
          return false;
        }
        break;
      case '[':
        openBraces.push(BracesType::SQUARE); break;
      case ']':
        if (!attemptPop(openBraces, BracesType::SQUARE)) {
          return false;
        }
        break;
      case '{':
        openBraces.push(BracesType::CURLY); break;
      case '}':
        if (!attemptPop(openBraces, BracesType::CURLY)) {
          return false;
        }
        break;
      default:
        throw "invalid string";
    }
  }
  return openBraces.empty();
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string equation;
    std::cin >> equation;
    std::cout << (isBalanced(equation) ? "YES" : "NO") << std::endl;
  }
  return 0;
}
