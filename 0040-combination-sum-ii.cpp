// LeetCode 40: Combination Sum II | Backtracking
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 vector<vector<int>> combinationSum2(vector<int>& a,int target) {
  sort(a.begin(),a.end());vector<vector<int>> ans;vector<int> path;
  function<void(int,int)> dfs=[&](int i,int rem){
   if(rem==0){ans.push_back(path);return;}
   for(int j=i;j<(int)a.size()&&a[j]<=rem;++j){
    if(j>i&&a[j]==a[j-1])continue;
    path.push_back(a[j]);dfs(j+1,rem-a[j]);path.pop_back();
   }
  };dfs(0,target);return ans;
 }
};