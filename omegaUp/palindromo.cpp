// https://omegaup.com/arena/problem/Palindromo

#include <iostream>
#include <string>

int main(){
  std::string s;
  std::cin >> s;
  for (unsigned i = 0; i < s.length() / 2; ++i) {
    if (s.at(i) != s.at(s.length() - i - 1)) {
      std::cout << "Falso";
      return 0;
    }
  }
  std::cout << "Cierto";
}
