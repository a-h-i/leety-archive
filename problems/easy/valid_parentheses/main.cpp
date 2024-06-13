#include "valid_parentheses.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> cases = {"()", "()[]{}", "(]", "([)]"};
  Solution sol;
  cout << boolalpha;
  for (auto &test : cases) {
    cout << sol.isValid(test) << endl;
  }
}