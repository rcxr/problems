// https://www.hackerrank.com/contests/w36/challenges/a-race-against-time

#include "bits/stdc++.h"
#include <unordered_map>

struct Student {
  Student(int height, int cost) : height(height), cost(cost) {}
  int const height;
  int const cost;
};

std::vector<Student> readStudents(int n) {
  std::vector<int> heights(n);
  for (auto i = 0; i < n; ++i) {
    std::cin >> heights[i];
  }
  std::vector<int> costs(n);
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

void fillCosts(std::vector<std::unordered_map<int, int>>& costs, std::vector<Student> const& students) {
  for (auto i = 0u; i < students.size(); ++i) {
    auto& student = students[i];
    auto& nextCosts = costs[i + 1];
    for (auto& prevCost : costs[i]) {
      auto height = prevCost.first;
      auto cost = prevCost.second;
      // Give baton
      auto givingCost = std::abs(height - student.height) + student.cost;
      if (nextCosts.end() == nextCosts.find(student.height) || cost + givingCost < nextCosts[student.height]) {
        nextCosts[student.height] = cost + givingCost;
      }
      // Do not give baton
      if (student.height <= height && (nextCosts.end() == nextCosts.find(height) || cost < nextCosts[height])) {
        nextCosts[height] = cost;
      }
    }
  }
}

int main() {
  // Read number of students
  int n;
  std::cin >> n;

  // Create cost tables for every position in the track
  std::vector<std::unordered_map<int, int>> costs(n);

  // The cost table for the start position is known: { { Mason's height, 0 } }
  int masonHeight;
  std::cin >> masonHeight;
  costs[0][masonHeight] = 0;

  // Read the n - 1 students
  auto students = readStudents(n - 1);

  // Fill costs based on the students data
  fillCosts(costs, students);

  // Find the best cost of the goal position
  auto max = std::min_element(
    costs[n - 1].begin(),
    costs[n - 1].end(),
    [](std::pair<int, int> const& a, std::pair<int, int> const& b) {
      return a.second < b.second;
    });

  // Print the best cost including the fixed cost of traveling n positions
  std::cout << (max->second + n);

  return 0;
}
