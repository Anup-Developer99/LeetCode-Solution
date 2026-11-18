// LeetCode 19: Remove Nth Node From End of List | O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0,head), *fast=&dummy, *slow=&dummy;
        for(int i=0;i<n;++i) fast=fast->next;
        while(fast->next) { fast=fast->next; slow=slow->next; }
        ListNode* del=slow->next;
        slow->next=del->next;
        delete del;
        return dummy.next;
    }
};