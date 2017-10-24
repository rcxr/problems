// https://omegaup.com/arena/problem/Anagramas

#include <iostream>
#include <string>
#include <algorithm>

int main(){
  int n;
  std::string a, b;
  std::cin >> n;
  while (0 < n--) {
    std::cin >> a >> b;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::cout << (a.compare(b) == 0 ? "si" : "no") << std::endl;
  }
}
