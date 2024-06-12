#include "palindrome.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;





int main() {

    vector<string> cases = {
        "abccccdd",
        "a"
    };

    Solution sol;

    for (const auto &test : cases) {
        cout << sol.longestPalindrome(test) << endl;
    }
}