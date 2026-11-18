// LeetCode 5: Longest Palindromic Substring
// Algorithm: Manacher's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int n = static_cast<int>(s.size());
        if (n <= 1) return s;

        // Separators are 0; input characters are stored as unsigned byte + 1.
        // This avoids collisions between separators and valid input characters.
        vector<int> transformed(2 * n + 1, 0);

        for (int i = 0; i < n; ++i) {
            transformed[2 * i + 1] =
                static_cast<unsigned char>(s[i]) + 1;
        }

        vector<int> radius(transformed.size(), 0);

        int center = 0;
        int right = 0;
        int bestCenter = 0;
        int bestRadius = 0;

        for (int i = 0; i < static_cast<int>(transformed.size()); ++i) {
            const int mirror = 2 * center - i;

            if (i < right) {
                radius[i] = min(right - i, radius[mirror]);
            }

            while (i - radius[i] - 1 >= 0 &&
                   i + radius[i] + 1 < static_cast<int>(transformed.size()) &&
                   transformed[i - radius[i] - 1] ==
                       transformed[i + radius[i] + 1]) {
                ++radius[i];
            }

            if (i + radius[i] > right) {
                center = i;
                right = i + radius[i];
            }

            if (radius[i] > bestRadius) {
                bestRadius = radius[i];
                bestCenter = i;
            }
        }

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

Important for LeetCode:
- Keep the class name exactly Solution.
- Keep the method name exactly longestPalindrome.
- Do not add main(); LeetCode supplies its own driver code.
*/
