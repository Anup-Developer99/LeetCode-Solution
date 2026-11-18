// LeetCode 59: Spiral Matrix II | O(n^2)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 vector<vector<int>> generateMatrix(int n) {
  vector<vector<int>> a(n,vector<int>(n));int top=0,bottom=n-1,left=0,right=n-1,x=1;
  while(top<=bottom&&left<=right){
   for(int c=left;c<=right;++c)a[top][c]=x++;++top;
   for(int r=top;r<=bottom;++r)a[r][right]=x++;--right;
   if(top<=bottom){for(int c=right;c>=left;--c)a[bottom][c]=x++;--bottom;}
   if(left<=right){for(int r=bottom;r>=top;--r)a[r][left]=x++;++left;}
  }return a;
 }
};