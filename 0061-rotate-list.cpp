// LeetCode 61: Rotate List | O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 ListNode* rotateRight(ListNode* head,int k) {
  if(!head||!head->next||k==0)return head;
  int n=1;ListNode* tail=head;while(tail->next){tail=tail->next;++n;}
  k%=n;if(!k)return head;tail->next=head;
  int steps=n-k;ListNode* newTail=head;while(--steps)newTail=newTail->next;
  ListNode* ans=newTail->next;newTail->next=nullptr;return ans;
 }
};