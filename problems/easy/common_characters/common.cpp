#include "common.hpp"
#include <algorithm>
#include <vector>
#include <limits>
#include <string>

using namespace std;

vector<string> Solution::commonChars(vector<string> &words)
{
    vector<int> frequencies(26, numeric_limits<int>::max());
    for (const string &word : words)
    {
        vector<int> charFrequenciesOfCurrentWord(26, 0);
        for (const char c : word)
        {
            charFrequenciesOfCurrentWord[c - 'a']++;
        }
        for (int character = 0; character < 26; character++)
        {
            frequencies[character] = min(frequencies[character], charFrequenciesOfCurrentWord[character]);
        }
    }

    vector<string> result;
    for (int i = 0; i < 26; i++)
    {
        result.insert(result.end(), frequencies[i], string({static_cast<char>('a' + i)}));
    }
    return result;
}