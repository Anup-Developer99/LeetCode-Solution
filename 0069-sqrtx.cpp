// LeetCode 69: Sqrt(x) | O(log x)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 int mySqrt(int x) {
  if(x<2)return x;long long l=1,r=x/2,ans=1;
  while(l<=r){long long m=l+(r-l)/2;if(m*m<=x){ans=m;l=m+1;}else r=m-1;}
  return (int)ans;
 }
};