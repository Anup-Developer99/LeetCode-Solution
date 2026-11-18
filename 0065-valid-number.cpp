// LeetCode 65: Valid Number | O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 bool isNumber(string s) {
  int i=0,n=s.size();while(i<n&&s[i]==' ')++i;
  if(i<n&&(s[i]=='+'||s[i]=='-'))++i;
  bool digit=false,dot=false,exp=false,expDigit=true;
  for(;i<n&&s[i]!=' ';++i){
   char c=s[i];
   if(isdigit((unsigned char)c)){digit=true;if(exp)expDigit=true;}
   else if(c=='.'&&!dot&&!exp)dot=true;
   else if((c=='e'||c=='E')&&!exp&&digit){exp=true;expDigit=false;if(i+1<n&&(s[i+1]=='+'||s[i+1]=='-'))++i;}
   else return false;
  }
  while(i<n&&s[i]==' ')++i;
  return i==n&&digit&&expDigit;
 }
};