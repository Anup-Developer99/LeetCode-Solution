// LeetCode 63: Unique Paths II | O(m*n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 int uniquePathsWithObstacles(vector<vector<int>>& a) {
  int m=a.size(),n=a[0].size();vector<long long> dp(n);dp[0]=a[0][0]==0;
  for(int r=0;r<m;++r)for(int c=0;c<n;++c){
   if(a[r][c])dp[c]=0;else if(c>0)dp[c]+=dp[c-1];
  }return (int)dp[n-1];
 }
};