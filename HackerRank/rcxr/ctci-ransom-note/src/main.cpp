// https://www.hackerrank.com/challenges/ctci-ransom-note

#include "bits/stdc++.h"
#include <unordered_map>

bool isSubset(std::unordered_map<std::string, int> const& noteWords, std::unordered_map<std::string, int> const& magazineWords) {
  for (std::pair<std::string, int> const& word : noteWords) {
    std::unordered_map<std::string, int>::const_iterator magazineIt = magazineWords.find(word.first);
    if (magazineWords.end() == magazineIt) {
      return false;
    }
    if (magazineIt->second < word.second) {
      return false;
    }
  }
  return true;
}

std::unordered_map<std::string, int> readWords(int size) {
  std::unordered_map<std::string, int> words;
  for (int i = 0; i < size; ++i) {
    std::string word;
    std::cin >> word;
    if (words.end() == words.find(word)) {
      words[word] = 0;
    }
    ++words[word];
  }
  return words;
}

int main() {
  int magazineSize, noteSize;
  std::cin >> magazineSize >> noteSize;

  std::unordered_map<std::string, int> magazineWords = readWords(magazineSize);
  std::unordered_map<std::string, int> noteWords = readWords(noteSize);

  std::cout << (isSubset(noteWords, magazineWords) ? "Yes" : "No");
  return 0;
}
