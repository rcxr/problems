// https://www.hackerrank.com/contests/hourrank-26/challenges/cloudy-day

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long maximumPeople(vector<long> cityPopulations, vector<long> cityPositions, vector<long> cloudPositions, vector<long> cloudRanges) {
  vector<pair<long, long>> cloudLimits;
  for (auto i = 0; i < cloudPositions.size(); ++i) {
    auto begin = cloudPositions[i] - cloudRanges[i];
    auto end = cloudPositions[i] + cloudRanges[i];
    cloudLimits.push_back(make_pair(i, begin));
    cloudLimits.push_back(make_pair(i, end));
  }
  sort(cloudLimits.begin(), cloudLimits.end(), [] (pair<long, long> const& a, pair<long, long> const& b) {
    return a.second > b.second;
  })

  vector<pair<long, long>> cities;
  for (auto i = 0; i < cityPositions.size(); ++i) {
    cities.push_back(make_pair(cityPositions[i], cityPopulations[i]));
  }
  sort(cities.begin(), cities.end(), [] (pair<long, long> const& a, pair<long, long> const& b) {
    return a.first > b.first;
  });

  auto currentCity = 0;
  set<long> activeClouds;
  unordered_map<long, long> utilities;
  for (auto i = 0; i < cloudLimits.size(); ++i) {
    auto city = cloudLimits[i].first;
    auto position = cloudLimits[i].second;

    auto it = activeClouds.find(city);
    if (activeClouds.end() == it) {
      activeClouds.insert(city);
    } else {
      activeClouds.erase(it, activeClouds.end());
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<long> p(n);
  for(int p_i = 0; p_i < n; p_i++){
    cin >> p[p_i];
  }
  vector<long> x(n);
  for(int x_i = 0; x_i < n; x_i++){
    cin >> x[x_i];
  }
  int m;
  cin >> m;
  vector<long> y(m);
  for(int y_i = 0; y_i < m; y_i++){
    cin >> y[y_i];
  }
  vector<long> r(m);
  for(int r_i = 0; r_i < m; r_i++){
    cin >> r[r_i];
  }
  long result = maximumPeople(p, x, y, r);
  cout << result << endl;
  return 0;
}
