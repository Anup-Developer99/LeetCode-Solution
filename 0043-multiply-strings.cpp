// LeetCode 43: Multiply Strings | O(m*n)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 string multiply(string a,string b) {
  if(a=="0"||b=="0")return "0";
  int m=a.size(),n=b.size();vector<int> v(m+n);
  for(int i=m-1;i>=0;--i)for(int j=n-1;j>=0;--j){
   int p=(a[i]-'0')*(b[j]-'0')+v[i+j+1];
   v[i+j+1]=p%10;v[i+j]+=p/10;
  }
  string s;int i=0;while(i<(int)v.size()&&v[i]==0)++i;
  for(;i<(int)v.size();++i)s+=char('0'+v[i]);return s;
 }
};