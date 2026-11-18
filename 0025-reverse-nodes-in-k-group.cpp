// LeetCode 25: Reverse Nodes in k-Group | O(n)
#include <bits/stdc++.h>
using namespace std;
// LeetCode provides ListNode.
class Solution { public:
 ListNode* reverseKGroup(ListNode* head,int k) {
  ListNode dummy(0,head),*groupPrev=&dummy;
  while(true){
   ListNode* kth=groupPrev;
   for(int i=0;i<k&&kth;++i)kth=kth->next;
   if(!kth)break;
   ListNode* groupNext=kth->next;
   ListNode* prev=groupNext,*cur=groupPrev->next;
   while(cur!=groupNext){ListNode* nxt=cur->next;cur->next=prev;prev=cur;cur=nxt;}
   ListNode* oldHead=groupPrev->next;
   groupPrev->next=kth;groupPrev=oldHead;
  }return dummy.next;
 }
};