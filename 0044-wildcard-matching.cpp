// LeetCode 44: Wildcard Matching | O(m*n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 bool isMatch(string s,string p) {
  int n=s.size();vector<char> dp(n+1,false);dp[0]=true;
  for(char c:p){
   if(c=='*'){for(int j=1;j<=n;++j)dp[j]=dp[j]||dp[j-1];}
   else{for(int j=n;j>=1;--j)dp[j]=(c=='?'||c==s[j-1])&&dp[j-1];dp[0]=false;}
  }return dp[n];
 }
};