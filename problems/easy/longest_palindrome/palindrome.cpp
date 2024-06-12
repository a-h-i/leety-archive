#include "palindrome.hpp"
#include <string>
#include <unordered_map>

using namespace std;

int Solution::longestPalindrome(string s)
{
    unordered_map<char, int> charFrequencyMap;

    for (const char &c : s)
    {
        if (charFrequencyMap.contains(c))
        {
            charFrequencyMap[c]++;
        }
        else
        {
            charFrequencyMap[c] = 1;
        }
    }

    int possibleSize = 0;
    for (auto &charFrequency : charFrequencyMap)
    {
        if (charFrequency.second % 2 == 0)
        {
            // take all even
            possibleSize += charFrequency.second;
            charFrequency.second = 0; // we have taken all repetition of this character
        }
        else if (charFrequency.second > 1)
        {
            // Odd number greater than one
            possibleSize += charFrequency.second - 1; // take max even
            charFrequency.second = 1;                 // we only left one repetition
        }
    }

    // now we can add a single character in the middle that only has one repetition left, doesn't matter if it was selected before or not
    for (auto &charFrequency : charFrequencyMap)
    {
        if (charFrequency.second == 1)
        {
            possibleSize += 1;
            charFrequency.second = 0; // not needed but to make it easier to extend
            break;
        }
    }
    return possibleSize;
}