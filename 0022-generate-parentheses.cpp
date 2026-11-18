// LeetCode 22: Generate Parentheses | O(Catalan(n) * n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        function<void(int,int)> dfs=[&](int open,int close) {
            if((int)path.size()==2*n) { ans.push_back(path); return; }
            if(open<n) { path+='('; dfs(open+1,close); path.pop_back(); }
            if(close<open) { path+=')'; dfs(open,close+1); path.pop_back(); }
        };
        dfs(0,0);
        return ans;
    }
};