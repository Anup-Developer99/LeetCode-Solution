// LeetCode 74: Search a 2D Matrix | O(log(m*n))
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 bool searchMatrix(vector<vector<int>>& a,int target) {
  int m=a.size(),n=a[0].size(),l=0,r=m*n-1;
  while(l<=r){int mid=l+(r-l)/2,x=a[mid/n][mid%n];if(x==target)return true;if(x<target)l=mid+1;else r=mid-1;}
  return false;
 }
};