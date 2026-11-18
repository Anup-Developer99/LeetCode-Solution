// LeetCode 16: 3Sum Closest | O(n^2)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long best=(long long)nums[0]+nums[1]+nums[2];
        for(int i=0;i+2<(int)nums.size();++i) {
            int l=i+1,r=nums.size()-1;
            while(l<r) {
                long long sum=(long long)nums[i]+nums[l]+nums[r];
                if(llabs(sum-target)<llabs(best-target)) best=sum;
                if(sum<target) ++l; else if(sum>target) --r; else return target;
            }
        }
        return (int)best;
    }
};