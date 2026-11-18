// LeetCode 58: Length of Last Word | O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 int lengthOfLastWord(string s) {
  int i=s.size()-1;while(i>=0&&s[i]==' ')--i;int len=0;
  while(i>=0&&s[i]!=' '){++len;--i;}return len;
 }
};