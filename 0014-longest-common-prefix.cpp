// LeetCode 14: Longest Common Prefix | O(total characters compared)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string p=strs[0];
        for(int i=1;i<(int)strs.size();++i) {
            int j=0;
            while(j<(int)p.size() && j<(int)strs[i].size() && p[j]==strs[i][j]) ++j;
            p.resize(j);
            if(p.empty()) break;
        }
        return p;
    }
};