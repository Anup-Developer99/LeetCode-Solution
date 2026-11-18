// LeetCode 7: Reverse Integer | O(number of digits)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long ans=0;
        while (x) {
            ans=ans*10+x%10;
            if (ans<INT_MIN || ans>INT_MAX) return 0;
            x/=10;
        }
        return (int)ans;
    }
};