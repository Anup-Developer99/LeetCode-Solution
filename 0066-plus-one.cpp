// LeetCode 66: Plus One | O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 vector<int> plusOne(vector<int>& digits) {
  for(int i=(int)digits.size()-1;i>=0;--i){if(++digits[i]<10)return digits;}
  digits[0]=0;digits.insert(digits.begin(),1);return digits;
 }
};