// LeetCode 6: Zigzag Conversion | O(n) time
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows<=1 || numRows >= (int)s.size()) return s;
        vector<string> rows(numRows);
        int r=0, dir=1;
        for (char c:s) {
            rows[r]+=c;
            if (r==0) dir=1;
            else if (r==numRows-1) dir=-1;
            r+=dir;
        }
        string ans;
        for (auto& row:rows) ans+=row;
        return ans;
    }
};