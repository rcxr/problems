#include <iostream>
int main(){
  long long answer = 1;
  for(int i = 1; i < 21; ++i) {
    answer = answer * (41 - i) / i;
  }
  std::cout << answer << std::endl;
  return 0;
}
