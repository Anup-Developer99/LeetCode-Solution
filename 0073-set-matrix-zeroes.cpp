// LeetCode 73: Set Matrix Zeroes | O(m*n) time, O(1) extra space
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 void setZeroes(vector<vector<int>>& a) {
  int m=a.size(),n=a[0].size();bool firstRow=false,firstCol=false;
  for(int c=0;c<n;++c)if(a[0][c]==0)firstRow=true;
  for(int r=0;r<m;++r)if(a[r][0]==0)firstCol=true;
  for(int r=1;r<m;++r)for(int c=1;c<n;++c)if(a[r][c]==0)a[r][0]=a[0][c]=0;
  for(int r=1;r<m;++r)for(int c=1;c<n;++c)if(a[r][0]==0||a[0][c]==0)a[r][c]=0;
  if(firstRow)fill(a[0].begin(),a[0].end(),0);
  if(firstCol)for(int r=0;r<m;++r)a[r][0]=0;
 }
};