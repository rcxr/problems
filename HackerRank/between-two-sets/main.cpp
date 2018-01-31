#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
  while (b) {
    auto t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int mcm(int a, int b) {
  return a * b / gcd(a, b);
}

int getTotalX(vector<int> as, vector<int> bs) {
  auto multiple = as[0];
  for (auto a : as) {
    multiple = mcm(a, multiple);
  }
  auto divisor = bs[0];
  for (auto b : bs) {
    divisor = gcd(b, divisor);
  }
  if (divisor % multiple) {
    return 0;
  }
  return divisor / multiple - 1;
}

int main() {
  int n;
  int m;
  cin >> n >> m;
  vector<int> a(n);
  for(auto i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for(auto i = 0; i < m; ++i) {
    cin >> b[i];
  }
  cout << getTotalX(a, b) << endl;
  return 0;
}
