// LeetCode 21: Merge Two Sorted Lists | O(m+n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy, *tail=&dummy;
        while(a && b) {
            if(a->val<=b->val) { tail->next=a; a=a->next; }
            else { tail->next=b; b=b->next; }
            tail=tail->next;
        }
        tail->next=a?a:b;
        return dummy.next;
    }
};