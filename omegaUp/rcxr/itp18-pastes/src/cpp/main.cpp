// https://omegaup.com/arena/problem/itp18-pastes

#include "bits/stdc++.h"

int main() {
  int n, papa, mole, hawai, zarza;
  std::cin >> papa >> mole >> hawai >> zarza >> n;
  while (n--) {
    int cPapa, cMole, cHawai, cZarza;
    std::cin >> cPapa >> cMole >> cHawai >> cZarza;
    papa -= cPapa;
    mole -= cMole;
    hawai -= cHawai;
    zarza -= cZarza;
  }
  if (papa < 0 || mole < 0 || hawai < 0 || zarza < 0) {
    std::cout << "#epicfail";
  } else {
    std::cout << "#win";
  }
  return 0;
}
