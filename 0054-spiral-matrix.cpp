// LeetCode 54: Spiral Matrix | O(m*n)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 vector<int> spiralOrder(vector<vector<int>>& a) {
  vector<int> ans;if(a.empty())return ans;
  int top=0,bottom=a.size()-1,left=0,right=a[0].size()-1;
  while(top<=bottom&&left<=right){
   for(int c=left;c<=right;++c)ans.push_back(a[top][c]);++top;
   for(int r=top;r<=bottom;++r)ans.push_back(a[r][right]);--right;
   if(top<=bottom){for(int c=right;c>=left;--c)ans.push_back(a[bottom][c]);--bottom;}
   if(left<=right){for(int r=bottom;r>=top;--r)ans.push_back(a[r][left]);++left;}
  }return ans;
 }
};