//
// Created by arsen on 25.06.2025.
//
#include <map>
#include <string>
class Solution {
public:
  bool canConstruct(std::string ransomNote, std::string magazine) {
    std::map<char, int> letters;
    for (char c : magazine) {
      letters[c]++;
    }
    for (int i = 0; i < ransomNote.size(); ++i) {
      if (letters[ransomNote[i]] - 1 >= 0) {
        letters[ransomNote[i]]--;
      } else {
        return false;
      }
    }
    return true;
  }
};