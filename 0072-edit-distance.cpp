// LeetCode 72: Edit Distance | O(m*n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 int minDistance(string a,string b) {
  int n=b.size();vector<int> dp(n+1);iota(dp.begin(),dp.end(),0);
  for(int i=1;i<=(int)a.size();++i){int prev=dp[0];dp[0]=i;
   for(int j=1;j<=n;++j){int old=dp[j];dp[j]=a[i-1]==b[j-1]?prev:1+min({prev,dp[j],dp[j-1]});prev=old;}
  }return dp[n];
 }
};