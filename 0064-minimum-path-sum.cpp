// LeetCode 64: Minimum Path Sum | O(m*n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 int minPathSum(vector<vector<int>>& g) {
  int m=g.size(),n=g[0].size();vector<int> dp(n,INT_MAX);dp[0]=0;
  for(int r=0;r<m;++r)for(int c=0;c<n;++c){
   if(c==0)dp[c]+=g[r][c];else dp[c]=min(dp[c],dp[c-1])+g[r][c];
  }return dp[n-1];
 }
};