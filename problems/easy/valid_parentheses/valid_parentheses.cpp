#include "valid_parentheses.hpp"
#include <stack>
#include <string>

using namespace std;

bool Solution::isValid(string s) {
  if (s.size() % 2 != 0) {
    return false;
  }
  stack<char> stack;

  for (const char element : s)

  {

    if (element == '(' || element == '[' || element == '{') {
      stack.push(element);
    } else {
      if (stack.empty()) {
        return false;
      }
      char front = stack.top();
      if (element == ')' && front != '(') {
        return false;
      } else if (element == ']' && front != '[') {
        return false;
      } else if (element == '}' && front != '{') {
        return false;
      } else {
        stack.pop();
      }
    }
  }
  return stack.empty();
}