// LeetCode 38: Count and Say | O(output size)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 string countAndSay(int n) {
  string s="1";
  for(int k=1;k<n;++k){string t;
   for(int i=0;i<(int)s.size();){int j=i;while(j<(int)s.size()&&s[j]==s[i])++j;
    t+=to_string(j-i);t+=s[i];i=j;
   } s=move(t);
  } return s;
 }
};