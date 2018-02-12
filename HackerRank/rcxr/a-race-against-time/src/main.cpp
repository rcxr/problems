// https://www.hackerrank.com/contests/w36/challenges/a-race-against-time

#include "bits/stdc++.h"

struct Student {
  Student(int height, long cost) : height(height), cost(cost) {}
  int const height;
  long const cost;
};

std::vector<Student> readStudents(int n) {
  std::vector<int> heights(n);
  for (auto i = 0; i < n; ++i) {
    std::cin >> heights[i];
  }
  std::vector<long> costs(n);
  for (auto i = 0; i < n; ++i) {
    std::cin >> costs[i];
  }
  std::vector<Student> students;
  students.reserve(n);
  for (auto i = 0; i < n; ++i) {
    students.emplace_back(heights[i], costs[i]);
  }
  return students;
}

std::map<int, long> calculateCosts(std::map<int, long> costs, std::vector<Student> const& students) {
  for (auto i = 0u; i < students.size(); ++i) {
    auto& student = students[i];
    std::map<int, long> nextCosts;
    std::vector<bool> valid(costs.size(), true);

    // Let's keep track of the best running cost
    int bestHeight;
    long bestCost;
    auto index = costs.size() - 1;

    // Let's discard costs that are dominated by the best running cost
    for (auto costIt = costs.rbegin(); costs.rend() != costIt; ++costIt) {
      if (costs.size() - 1 == index) {
        --index;
        bestHeight = costIt->first;
        bestCost = costIt->second;
        continue;
      }
      auto hypoteticalCost = bestCost + abs(costIt->first - bestHeight);
      if (hypoteticalCost <= costIt->second) {
        valid[index] = false;
      } else {
        bestHeight = costIt->first;
        bestCost = costIt->second;
      }
      --index;
    }

    index = 0;
    for (auto& prev : costs) {
      auto prevHeight = prev.first;
      auto prevCost = prev.second;

      // Short-circuit if cost is dominated
      if (!valid[index++]) {
        continue;
      }

      auto givingCost = std::abs(prevHeight - student.height) + student.cost + prevCost;

      // Give baton
      if (nextCosts.end() == nextCosts.find(student.height) || givingCost < nextCosts[student.height]) {
        nextCosts[student.height] = givingCost;
      }

      // Giving is required if student is taller
      if (prevHeight < student.height) {
        continue;
      }

      // Do not give baton
      if (nextCosts.end() == nextCosts.find(prevHeight) || prevCost < nextCosts[prevHeight]) {
        nextCosts[prevHeight] = prevCost;
      }
    }

    costs = nextCosts;
  }

  return costs;
}

int main() {
  // Read number of students
  int n;
  std::cin >> n;

  // The costs for the start position is known: { { Mason's height, 0 } }
  int masonHeight;
  std::cin >> masonHeight;
  std::map<int, long> costs;
  costs[masonHeight] = 0;

  // Read the n - 1 students
  auto students = readStudents(n - 1);

  // Calculate final costs based on the students data
  costs = calculateCosts(costs, students);

  // Find the best cost of the goal position
  auto min = std::min_element(
    costs.begin(),
    costs.end(),
    [](std::pair<int, long> const& a, std::pair<int, long> const& b) {
      return a.second < b.second;
    });

  // Print the best cost including the fixed cost of traveling n positions
  std::cout << min->second + n;

  return 0;
}
