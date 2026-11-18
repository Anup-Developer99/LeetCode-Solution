// LeetCode 55: Jump Game | O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 bool canJump(vector<int>& nums) {
  int reach=0;
  for(int i=0;i<(int)nums.size();++i){if(i>reach)return false;reach=max(reach,i+nums[i]);}
  return true;
 }
};