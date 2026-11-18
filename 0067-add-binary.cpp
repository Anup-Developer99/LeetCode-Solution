// LeetCode 67: Add Binary | O(max(n,m))
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 string addBinary(string a,string b) {
  string ans;int i=a.size()-1,j=b.size()-1,carry=0;
  while(i>=0||j>=0||carry){int s=carry+(i>=0?a[i--]-'0':0)+(j>=0?b[j--]-'0':0);ans.push_back(char('0'+s%2));carry=s/2;}
  reverse(ans.begin(),ans.end());return ans;
 }
};