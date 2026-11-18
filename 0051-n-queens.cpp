// LeetCode 51: N-Queens | Backtracking
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> ans;vector<string> b(n,string(n,'.'));
  vector<char> col(n),d1(2*n-1),d2(2*n-1);
  function<void(int)> dfs=[&](int r){
   if(r==n){ans.push_back(b);return;}
   for(int c=0;c<n;++c)if(!col[c]&&!d1[r-c+n-1]&&!d2[r+c]){
    col[c]=d1[r-c+n-1]=d2[r+c]=1;b[r][c]='Q';dfs(r+1);b[r][c]='.';
    col[c]=d1[r-c+n-1]=d2[r+c]=0;
   }
  };dfs(0);return ans;
 }
};