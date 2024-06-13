#include "two_sum.hpp"
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> Solution::twoSum(const vector<int> &nums, int target) {
  unordered_map<int, int> diffs;
  for (int i = 0; i < nums.size(); i++) {
    auto complementElement = diffs.find(nums[i]);
    if (complementElement != diffs.end() && complementElement->second != i) {
      return {i, complementElement->second};
    }
    const int diff = target - nums[i];
    diffs[diff] = i;
  }

  return {};
}