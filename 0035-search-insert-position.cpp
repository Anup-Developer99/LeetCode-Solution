// LeetCode 35: Search Insert Position | O(log n)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 int searchInsert(vector<int>& nums,int target) {
  return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
 }
};