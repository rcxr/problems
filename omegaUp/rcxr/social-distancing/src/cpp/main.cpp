// https://omegaup.com/arena/problem/social-distancing

#include "bits/stdc++.h"

class Customer {
public:
  Customer(int groupId, int x, int y) {
    this->groupId = groupId;
    this->x = x;
    this->y = y;
  }
private:
  int groupId;
  int x;
  int y;
  std::set<int> neighborsH;
  std::set<int> neighborsV;
};

bool isPasilloSafe(std::vector<Customer> &customers, int w, int l) {
  return true;
}

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int c, w, l;
    std::cin >> c >> w >> l;

    std::vector<Customer> customers;
    for (int j = 0; j < c; ++j) {
      int x, y;
      std::cin >> x >> y;
      customers.push_back(Customer(j, x, y));
    }

    std::cout << (isPasilloSafe(customers, w, l) ? "SAFE" : "RISKY") << std::endl;
  }

  return 0;
}
