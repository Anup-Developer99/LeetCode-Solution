// LeetCode 57: Insert Interval | O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 vector<vector<int>> insert(vector<vector<int>>& a,vector<int>& x) {
  vector<vector<int>> ans;int i=0,n=a.size();
  while(i<n&&a[i][1]<x[0])ans.push_back(a[i++]);
  while(i<n&&a[i][0]<=x[1]){x[0]=min(x[0],a[i][0]);x[1]=max(x[1],a[i][1]);++i;}
  ans.push_back(x);while(i<n)ans.push_back(a[i++]);return ans;
 }
};