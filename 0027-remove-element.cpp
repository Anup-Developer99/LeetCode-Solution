// LeetCode 27: Remove Element | O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 int removeElement(vector<int>& nums,int val) {
  int k=0; for(int x:nums) if(x!=val) nums[k++]=x;
  return k;
 }
};