// https://omegaup.com/arena/problem/abc

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int lbs(unsigned num) {
    unsigned mask = 1;
    for (int cnt = 0; ++cnt <= 32; mask <<= 1) {
        if (num & mask) {
            return cnt;
        }
    }
    return 0;
}

int main() {
  for (unsigned i = 0; i < 256; ++i) {
    if (i % 16 == 0) {
      cout << endl;
    }
    cout << lbs(i) << ", ";
  }
  return 0;
}
