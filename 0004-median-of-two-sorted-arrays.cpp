// LeetCode 4: Median of Two Sorted Arrays | O(log(min(m,n)))
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) return findMedianSortedArrays(b, a);
        int m=a.size(), n=b.size(), lo=0, hi=m;
        while (lo<=hi) {
            int i=lo+(hi-lo)/2, j=(m+n+1)/2-i;
            int al=i? a[i-1]:INT_MIN, ar=i<m? a[i]:INT_MAX;
            int bl=j? b[j-1]:INT_MIN, br=j<n? b[j]:INT_MAX;
            if (al<=br && bl<=ar) {
                if ((m+n)&1) return max(al,bl);
                return (max(al,bl)+ (double)min(ar,br))/2.0;
            }
            if (al>br) hi=i-1; else lo=i+1;
        }
        return 0.0;
    }
};