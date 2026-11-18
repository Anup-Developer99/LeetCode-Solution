// LeetCode 3: Longest Substring Without Repeating Characters
// Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Approach: Sliding Window + Hash Map
// Time Complexity: O(n) average
// Space Complexity: O(min(n, character_set_size))

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Store the most recent index at which each character appeared.
        unordered_map<char, int> lastSeen;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            const char current = s[right];

            // Move left only when the previous occurrence is in this window.
            auto it = lastSeen.find(current);
            if (it != lastSeen.end() && it->second >= left) {
                left = it->second + 1;
            }

            // Record the current character's latest index.
            lastSeen[current] = right;

            // Current window [left, right] contains unique characters.
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

/*
Example:
Input:  s = "abcabcbb"
Output: 3
Explanation: "abc", "bca", and "cab" are valid longest substrings.

Other test cases:
"bbbbb" -> 1
"pwwkew" -> 3
""       -> 0
"abba"   -> 2
"dvdf"   -> 3

Note:
This char-based implementation is suitable for the usual ASCII-style
LeetCode test cases. For full Unicode code-point handling, a different
string representation/iteration strategy is required.
*/
