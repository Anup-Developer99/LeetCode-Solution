// LeetCode 5: Longest Palindromic Substring
// Problem: https://leetcode.com/problems/longest-palindromic-substring/
// Algorithm: Manacher's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(n)
//
// The input is guaranteed to contain only English letters and digits.
// Transforming the string with separator values makes odd/even palindromes
// use the same expansion logic. Character values are stored as integers,
// so the separator cannot collide with an input character.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int n = static_cast<int>(s.size());
        if (n <= 1) return s;

        // Transformed layout: # a # b # a #
        // 0 is a separator; input bytes are stored as unsigned-char + 1.
        vector<int> t(2 * n + 1, 0);
        for (int i = 0; i < n; ++i) {
            t[2 * i + 1] = static_cast<unsigned char>(s[i]) + 1;
        }

        // p[i] = palindrome radius around transformed index i.
        vector<int> p(t.size(), 0);

        int center = 0;
        int right = 0;       // Rightmost boundary reached by current palindrome.
        int bestCenter = 0;
        int bestRadius = 0;

        for (int i = 0; i < static_cast<int>(t.size()); ++i) {
            // Mirror the known radius when i is inside the current right edge.
            const int mirror = 2 * center - i;
            if (i < right) {
                p[i] = min(right - i, p[mirror]);
            }

            // Expand while both sides match and remain in bounds.
            while (i - p[i] - 1 >= 0 &&
                   i + p[i] + 1 < static_cast<int>(t.size()) &&
                   t[i - p[i] - 1] == t[i + p[i] + 1]) {
                ++p[i];
            }

            // Update the rightmost palindrome.
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            // Keep the first maximum if multiple answers have equal length.
            if (p[i] > bestRadius) {
                bestRadius = p[i];
                bestCenter = i;
            }
        }

        // In this transformed representation, radius equals original length.
        const int start = (bestCenter - bestRadius) / 2;
        return s.substr(start, bestRadius);
    }
};

/*
Examples:
"babad" -> "bab" (or "aba")
"cbbd"  -> "bb"
"a"     -> "a"
"ac"    -> "a" (or "c")
"aaaa"  -> "aaaa"

Why Manacher:
- Checks all palindrome centers in linear time.
- Reuses previously computed palindrome radii through mirror positions.
- Avoids the O(n^2) worst-case time of center expansion / DP.
- Runtime cannot literally be zero; O(n) is asymptotically optimal because
  the input must be examined.
*/
