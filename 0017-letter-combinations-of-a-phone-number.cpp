// LeetCode 17: Letter Combinations of a Phone Number | O(4^n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        const vector<string> map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string path;
        function<void(int)> dfs=[&](int i) {
            if(i==(int)digits.size()) { ans.push_back(path); return; }
            for(char c:map[digits[i]-'0']) { path+=c; dfs(i+1); path.pop_back(); }
        };
        dfs(0);
        return ans;
    }
};