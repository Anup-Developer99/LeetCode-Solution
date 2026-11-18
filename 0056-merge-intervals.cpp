// LeetCode 56: Merge Intervals | O(n log n)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 vector<vector<int>> merge(vector<vector<int>>& a) {
  sort(a.begin(),a.end());vector<vector<int>> ans;
  for(auto& x:a){if(ans.empty()||ans.back()[1]<x[0])ans.push_back(x);else ans.back()[1]=max(ans.back()[1],x[1]);}
  return ans;
 }
};