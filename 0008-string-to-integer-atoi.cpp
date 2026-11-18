// LeetCode 8: String to Integer (atoi) | O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.size(),sign=1;
        while(i<n && s[i]==' ') ++i;
        if(i<n && (s[i]=='+' || s[i]=='-')) { if(s[i++]=='-') sign=-1; }
        long long value=0;
        while(i<n && isdigit((unsigned char)s[i])) {
            value=value*10+(s[i++]-'0');
            if(sign==1 && value>INT_MAX) return INT_MAX;
            if(sign==-1 && -value<INT_MIN) return INT_MIN;
        }
        return (int)(sign*value);
    }
};