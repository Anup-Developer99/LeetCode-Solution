// LeetCode 52: N-Queens II | Backtracking
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 int totalNQueens(int n) {
  vector<char> col(n),d1(2*n-1),d2(2*n-1);int ans=0;
  function<void(int)> dfs=[&](int r){
   if(r==n){++ans;return;}
   for(int c=0;c<n;++c)if(!col[c]&&!d1[r-c+n-1]&&!d2[r+c]){
    col[c]=d1[r-c+n-1]=d2[r+c]=1;dfs(r+1);
    col[c]=d1[r-c+n-1]=d2[r+c]=0;
   }
  };dfs(0);return ans;
 }
};