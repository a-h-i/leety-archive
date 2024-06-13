#include "straights.hpp"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  Solution s;
  vector<pair<vector<int>, int>> cases = {{{1, 2, 3, 6, 2, 3, 4, 7, 8}, 3},
                                          {{1, 2, 3, 4, 5}, 4}};

  for (auto &test : cases) {
    std::cout << s.isNStraightHand(test.first, test.second) << endl;
  }
}