// LeetCode 29: Divide Two Integers | O(log(INT_MAX))
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 int divide(int dividend,int divisor) {
  if(dividend==INT_MIN && divisor==-1) return INT_MAX;
  long long a=llabs((long long)dividend),b=llabs((long long)divisor),q=0;
  for(int bit=31;bit>=0;--bit) if((a>>bit)>=b) { a-=b<<bit; q|=1LL<<bit; }
  if((dividend<0)^(divisor<0)) q=-q;
  return (int)q;
 }
};