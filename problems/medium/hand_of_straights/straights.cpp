#include "straights.hpp"
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

bool Solution::isNStraightHand(vector<int> &hand, int groupSize) {
  if (hand.size() % groupSize != 0) {
    return false;
  }
  unordered_map<int, int> frequencies;
  for (auto number : hand) {
    frequencies[number]++;
  }

  for (int card : hand) {
    int possibleStart = card;
    if (frequencies[possibleStart] == 0) {
      continue;
    }

    while (frequencies[possibleStart - 1] > 0) {
      // while predecessor exists
      possibleStart--;
    }

    for (int successor = possibleStart; successor < possibleStart + groupSize;
         successor++) {
      if (frequencies[successor]-- == 0) {
        return false;
      }
    }
  }
  return true;
}