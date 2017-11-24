// http://codeforces.com/problemset/problem/4/A

#include <iostream>

int main(){
  unsigned i;
  std::cin >> i;
  std::cout << (i % 2 || i == 2 ? "NO" : "YES");
}
