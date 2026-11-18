// LeetCode 71: Simplify Path | O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 string simplifyPath(string path) {
  vector<string> st;stringstream ss(path);string part;
  while(getline(ss,part,'/')){if(part.empty()||part==".")continue;if(part==".."){if(!st.empty())st.pop_back();}else st.push_back(part);}
  string ans="/";for(int i=0;i<(int)st.size();++i){if(i)ans+="/";ans+=st[i];}return ans;
 }
};