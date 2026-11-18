// LeetCode 60: Permutation Sequence | O(n^2)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 string getPermutation(int n,int k) {
  vector<int> nums(n);iota(nums.begin(),nums.end(),1);
  vector<int> fact(n+1,1);for(int i=1;i<=n;++i)fact[i]=fact[i-1]*i;
  --k;string ans;
  for(int i=n;i>=1;--i){int idx=k/fact[i-1];k%=fact[i-1];ans+=to_string(nums[idx]);nums.erase(nums.begin()+idx);}
  return ans;
 }
};