// LeetCode 39: Combination Sum | Backtracking
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 vector<vector<int>> combinationSum(vector<int>& a,int target) {
  sort(a.begin(),a.end());vector<vector<int>> ans;vector<int> path;
  function<void(int,int)> dfs=[&](int i,int rem){
   if(rem==0){ans.push_back(path);return;}
   for(int j=i;j<(int)a.size()&&a[j]<=rem;++j){
    if(j>i&&a[j]==a[j-1])continue;
    path.push_back(a[j]);dfs(j,rem-a[j]);path.pop_back();
   }
  };dfs(0,target);return ans;
 }
};