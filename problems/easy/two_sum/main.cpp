#include "two_sum.hpp"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  Solution sol;
  vector<pair<vector<int>, int>> cases = {
      {{2, 7, 11, 15}, 9}, {{3, 2, 4}, 6}, {{3, 3}, 6}};

  for (const auto &test : cases) {
    const vector<int> result = sol.twoSum(test.first, test.second);
    for (int element : result) {
      cout << element << ",";
    }
    cout << endl;
  }
}