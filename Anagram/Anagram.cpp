/*
This program checks whether the two input strings are anagrams or not.
*/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>

bool isAnagram_sort(std::string s, std::string t) {
  if (s.size() != t.size())
    return false;
  std::sort(s.begin(), s.end());
  std::sort(t.begin(), t.end());
  return t == s;
}

bool isAnagram_equal(const std::string &s, const std::string &t) {
  if (s.size() != t.size())
    return false;
  const auto freq_map = [](const std::string &s) {
    std::unordered_map<char, int> temp{};
    for (const auto &i : s) {
      temp[i]++; // increment the value of the key i
    }
    return temp;
  };
  return freq_map(s) == freq_map(t);
}

auto main() -> int {
  std::string t{"yahya"};
  std::string s{"ayahy"};
  std::string k{"ayag"};

  std::cout << isAnagram_equal(t, s) << '\n';
}

/*
  INPUT:
  s1="abc"
  s2="cba"
  OUTPUT:
    Given strings are anagrams

  INPUT:
    s1="abc"
    s2="azs"
  OUTPUT:
    Given strings are not anagrams
*/
