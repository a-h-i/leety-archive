#include "common.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<vector<string>> cases = {
        {"bella", "label", "roller"},
        {"cool", "lock", "cook"}};
    Solution sol;
    for(auto &test : cases) {
        const auto result = sol.commonChars(test); 
        for (const auto &word : result) {
            cout << word << ", ";
        }
        cout << endl;
    }
}