// LeetCode 30: Substring with Concatenation of All Words | O(n*k)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 vector<int> findSubstring(string s,vector<string>& words) {
  vector<int> ans; if(words.empty()||words[0].empty()) return ans;
  int w=words[0].size(),total=w*words.size();
  if((int)s.size()<total) return ans;
  unordered_map<string,int> need;
  for(auto& x:words) ++need[x];
  for(int off=0;off<w;++off) {
   unordered_map<string,int> have; int left=off,count=0;
   for(int right=off;right+w<=(int)s.size();right+=w) {
    string x=s.substr(right,w);
    if(!need.count(x)) {have.clear();count=0;left=right+w;continue;}
    ++have[x];++count;
    while(have[x]>need[x]) {string y=s.substr(left,w);--have[y];--count;left+=w;}
    if(count==(int)words.size()) {ans.push_back(left);string y=s.substr(left,w);--have[y];--count;left+=w;}
   }
  }
  sort(ans.begin(),ans.end()); return ans;
 }
};