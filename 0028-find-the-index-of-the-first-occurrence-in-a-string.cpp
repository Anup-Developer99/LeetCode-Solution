// LeetCode 28: Find the Index of the First Occurrence | O(n*m) worst case
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 int strStr(string haystack,string needle) {
  size_t p=haystack.find(needle);
  return p==string::npos?-1:(int)p;
 }
};