#include "palindrome.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  vector<string> cases = {"abccccdd", "a"};

  Solution sol;

  for (const auto &test : cases) {
    cout << sol.longestPalindrome(test) << endl;
  }
}