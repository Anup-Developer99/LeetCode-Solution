// LeetCode 15: 3Sum | O(n^2) time, O(1) extra space excluding output
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<(int)nums.size();++i) {
            if(i && nums[i]==nums[i-1]) continue;
            int l=i+1,r=nums.size()-1;
            while(l<r) {
                long long sum=(long long)nums[i]+nums[l]+nums[r];
                if(sum<0) ++l;
                else if(sum>0) --r;
                else {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    int a=nums[l],b=nums[r];
                    while(l<r && nums[l]==a) ++l;
                    while(l<r && nums[r]==b) --r;
                }
            }
        }
        return ans;
    }
};