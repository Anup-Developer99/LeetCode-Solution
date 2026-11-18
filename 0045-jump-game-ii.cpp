// LeetCode 45: Jump Game II | O(n) greedy
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 int jump(vector<int>& nums) {
  int jumps=0,end=0,far=0;
  for(int i=0;i+1<(int)nums.size();++i){
   far=max(far,i+nums[i]);
   if(i==end){++jumps;end=far;}
  }return jumps;
 }
};