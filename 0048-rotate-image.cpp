// LeetCode 48: Rotate Image | O(n^2) time, O(1) extra space
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 void rotate(vector<vector<int>>& a) {
  int n=a.size();
  for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)swap(a[i][j],a[j][i]);
  for(auto& row:a)reverse(row.begin(),row.end());
 }
};