// LeetCode 10: Regular Expression Matching | O(m*n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 bool isMatch(string s,string p) {
  int n=s.size();vector<char> dp(n+1,false);dp[0]=true;
  for(int j=1;j<=(int)p.size();++j) {
   if(p[j-1]=='*') {
    dp[0]=dp[0] && j>=2 && p[j-2]!='*';
    for(int i=1;i<=n;++i) {
     if(j<2) dp[i]=false;
     else dp[i]=dp[i] || ((p[j-2]=='.'||p[j-2]==s[i-1]) && dp[i]);
    }
   } else {
    for(int i=n;i>=1;--i)dp[i]=(p[j-1]=='.'||p[j-1]==s[i-1])&&dp[i-1];
    dp[0]=false;
   }
  }return dp[n];
 }
};