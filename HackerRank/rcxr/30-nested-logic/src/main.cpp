// https://www.hackerrank.com/challenges/30-nested-logic

#include "bits/stdc++.h"

int const FEE_DAY = 15;
int const FEE_MONTH = 500;
int const FEE_YEAR = 10000;

int calculateFee(int aDay, int aMonth, int aYear, int bDay, int bMonth, int bYear) {
  if (aYear < bYear) {
    return 0;
  } else if (bYear < aYear) {
    return FEE_YEAR;
  }
  if (aMonth < bMonth) {
    return 0;
  } else if (bMonth < aMonth) {
    return FEE_MONTH * (aMonth - bMonth);
  }
  if (aDay < bDay) {
    return 0;
  } else if (bDay < aDay) {
    return FEE_DAY * (aDay - bDay);
  }
  return 0;
}

int main() {
  int aDay, aMonth, aYear;
  int bDay, bMonth, bYear;
  std::cin >> aDay >> aMonth >> aYear >> bDay >> bMonth >> bYear;
  std::cout << calculateFee(aDay, aMonth, aYear, bDay, bMonth, bYear);
  return 0;
}
