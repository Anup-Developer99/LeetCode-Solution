// LeetCode 24: Swap Nodes in Pairs | O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0,head), *prev=&dummy;
        while(prev->next && prev->next->next) {
            ListNode* a=prev->next;
            ListNode* b=a->next;
            a->next=b->next; b->next=a; prev->next=b;
            prev=a;
        }
        return dummy.next;
    }
};