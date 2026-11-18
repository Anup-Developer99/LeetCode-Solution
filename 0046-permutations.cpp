// LeetCode 46: Permutations | O(n*n!)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> ans;
  function<void(int)> dfs=[&](int i){
   if(i==(int)nums.size()){ans.push_back(nums);return;}
   for(int j=i;j<(int)nums.size();++j){swap(nums[i],nums[j]);dfs(i+1);swap(nums[i],nums[j]);}
  };dfs(0);return ans;
 }
};