// LeetCode 42: Trapping Rain Water | O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 int trap(vector<int>& h) {
  int l=0,r=(int)h.size()-1,lm=0,rm=0,ans=0;
  while(l<r)if(h[l]<h[r]){lm=max(lm,h[l]);ans+=lm-h[l++];}
  else{rm=max(rm,h[r]);ans+=rm-h[r--];}
  return ans;
 }
};