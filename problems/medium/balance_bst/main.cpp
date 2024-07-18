#include <array>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *balanceBST(TreeNode *root) {
    deque<TreeNode *> sortedArray;
    this->inOrderTraversal(
        root, [&sortedArray](TreeNode *node) { sortedArray.push_back(node); });
    return this->arrayToTree(sortedArray.begin(), sortedArray.end() - 1);
  }
  template <typename RandomAccessIterator>
    requires random_access_iterator<TreeNode *>
  TreeNode *arrayToTree(RandomAccessIterator start, RandomAccessIterator end) {

    if (start > end) {
      return nullptr;
    }
    auto midOffset = (end - start) / 2;
    auto mid = start + midOffset;
    auto root = *mid;
    root->left = this->arrayToTree(start, mid - 1);
    root->right = this->arrayToTree(mid + 1, end);
    return root;
  }

  void inOrderTraversal(TreeNode *root,
                        const function<void(TreeNode *)> &visitAction) {

    deque<TreeNode *> stack;
    auto current = root;

    while (current != nullptr || !stack.empty()) {
      if (current != nullptr) {
        stack.push_back(current);
        current = current->left;
      } else {
        current = stack.back();
        stack.pop_back();
        visitAction(current);
        current = current->right;
      }
    }
  }
};

int main() {

  array<TreeNode, 4> nodes;
  for (int i = 0; i < 4; i++) {
    nodes[i].val = i + 1;
    if (i < 3) {
      nodes[i].right = &nodes[i + 1];
    }
  }
  Solution s;
  s.inOrderTraversal(&nodes[0], [](TreeNode *node) {cout << node->val << " - ";});
  cout << endl;
  auto balancedRoot = s.balanceBST(&nodes[0]);
  cout << balancedRoot->val << endl;
  return 0;
}