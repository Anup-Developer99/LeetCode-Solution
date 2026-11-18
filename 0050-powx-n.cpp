// LeetCode 50: Pow(x, n) | O(log n)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 double myPow(double x,int n) {
  long long e=n;if(e<0){x=1.0/x;e=-e;}
  double ans=1.0;
  while(e){if(e&1)ans*=x;x*=x;e>>=1;}
  return ans;
 }
};