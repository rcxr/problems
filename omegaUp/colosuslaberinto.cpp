// https://omegaup.com/arena/problem/Palindromo

#include <iostream>
#include <string>
#include <vector>
#include <climits>

int main(){
  unsigned n, m, t;
  std::cin >> n >> m >> t;

  char* map = new char[n * m];
  unsigned * cost = new unsigned[n * m]();

  for (unsigned i = 0; i < n * m; ++i) {
    std::cin >> char[i];
    if (s.at(i) != s.at(s.length() - i - 1)) {
      std::cout << "Falso";
      return 0;
    }
  }
  std::cout << "Cierto";
}
