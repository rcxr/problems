// https://www.hackerrank.com/contests/hourrank-26/challenges/cloudy-day

#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>

std::map<int, long> calculateUtilities(std::vector<int> const& townXs, std::vector<int> const& townPopulations) {
  std::map<int, long> utilities;
  for (auto i = 0u; i < townXs.size(); ++i) {
    if (utilities.end() == utilities.find(townXs[i])) {
      utilities[townXs[i]] = 0l;
    }
    utilities[townXs[i]] += townPopulations[i];
  }
  return utilities;
}

void addCloudTransition(std::map<int, std::vector<unsigned>>& cloudTransitions, int x, unsigned cloudId) {
  if (cloudTransitions.end() != cloudTransitions.find(x)) {
    cloudTransitions[x] = std::vector<unsigned>();
  }
  cloudTransitions[x].push_back(cloudId);
}

std::map<int, std::vector<unsigned>> calculateCloudTransitions(std::vector<int> const& cloudXs, std::vector<int> const& cloudRanges) {
  std::map<int, std::vector<unsigned>> cloudTransitions;
  for (auto i = 0u; i < cloudXs.size(); ++i) {
    addCloudTransition(cloudTransitions, cloudXs[i] - cloudRanges[i], i);
    addCloudTransition(cloudTransitions, cloudXs[i] + cloudRanges[i] + 1, i);
  }
  return cloudTransitions;
}

long maxUtility(
  std::vector<int> const& townXs,
  std::vector<int> const& townPopulations,
  std::vector<int> const& cloudXs,
  std::vector<int> const& cloudRanges) {
  // Cloud transitions
  auto cloudTransitions = calculateCloudTransitions(cloudXs, cloudRanges);

  // Utility per position
  auto utilities = calculateUtilities(townXs, townPopulations);

  // Utility trackers
  std::unordered_set<unsigned> activeClouds;
  std::unordered_map<unsigned, long> cloudUtilities;
  auto utilityIt = utilities.begin();
  auto utility = 0l;

  for (auto cloudTransition : cloudTransitions) {
    // Toggle the cloud active states for this position
    for (auto cloudId : cloudTransition.second) {
      auto activeCloudIt = activeClouds.find(cloudId);
      if (activeClouds.end() == activeCloudIt) {
        // If the cloud was not active, activate it
        activeClouds.insert(cloudId);
      } else {
        // If the cloud was active, deactivate it
        activeClouds.erase(activeCloudIt);
      }
    }

    // Consume utilities
    while (utilities.end() != utilityIt && utilityIt->first <= cloudTransition.first) {
      if (activeClouds.empty()) {
        utility += utilityIt->second;
      } else if (1u == activeClouds.size()) {
        auto cloudId = *(activeClouds.begin());
        if (cloudUtilities.end() == cloudUtilities.find(cloudId)) {
          cloudUtilities[cloudId] = 0l;
        }
        cloudUtilities[cloudId] += utilityIt->second;
      }
    }

    // Determine if we can short-circuit
    if (utilities.end() == utilityIt) {
      break;
    }
  }

  // Consume the remaining utilities, they are guaranteed to not be covered by clouds
  while (utilities.end() != utilityIt) {
    utility += utilityIt->second;
    ++utilityIt;
  }

  // Return the max utility (normal utility + max cloud utility)
  auto max = max_element(cloudUtilities.begin(), cloudUtilities.end(), [] (std::pair<unsigned, long> const& a, std::pair<unsigned, long> const& b) {
    return a.second < b.second;
  });
  return utility + (cloudUtilities.end() == max ? 0l : max->second);
}

int main() {
  // Number of towns
  unsigned towns;
  std::cin >> towns;

  // Town populations
  std::vector<int> townPopulations(towns);
  for(auto i = 0u; i < towns; ++i) {
    std::cin >> townPopulations[i];
  }

  // Town positions
  std::vector<int> townXs(towns);
  for(auto i = 0u; i < towns; ++i) {
    std::cin >> townXs[i];
  }

  // Number of clouds
  unsigned clouds;
  std::cin >> clouds;

  // Cloud positions
  std::vector<int> cloudXs(clouds);
  for(auto i = 0u; i < clouds; ++i) {
    std::cin >> cloudXs[i];
  }

  // Cloud ranges
  std::vector<int> cloudRanges(clouds);
  for(auto i = 0u; i < clouds; ++i) {
    std::cin >> cloudRanges[i];
  }

  std::cout << maxUtility(townXs, townPopulations, cloudXs, cloudRanges) << std::endl;
  return 0;
}
