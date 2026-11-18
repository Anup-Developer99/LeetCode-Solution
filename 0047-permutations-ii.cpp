// LeetCode 47: Permutations II | O(n*n!)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 vector<vector<int>> permuteUnique(vector<int>& nums) {
  sort(nums.begin(),nums.end());vector<vector<int>> ans;vector<int> path;vector<char> used(nums.size());
  function<void()> dfs=[&](){
   if(path.size()==nums.size()){ans.push_back(path);return;}
   for(int i=0;i<(int)nums.size();++i)if(!used[i]){
    if(i&&nums[i]==nums[i-1]&&!used[i-1])continue;
    used[i]=1;path.push_back(nums[i]);dfs();path.pop_back();used[i]=0;
   }
  };dfs();return ans;
 }
};