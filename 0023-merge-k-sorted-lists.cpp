// LeetCode 23: Merge k Sorted Lists | O(N log k)
#include <bits/stdc++.h>
using namespace std;
// LeetCode provides ListNode.
class Solution { public:
 ListNode* mergeKLists(vector<ListNode*>& lists) {
  auto cmp=[](ListNode* a,ListNode* b){return a->val>b->val;};
  priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
  for(auto node:lists)if(node)pq.push(node);
  ListNode dummy,*tail=&dummy;
  while(!pq.empty()){
   ListNode* node=pq.top();pq.pop();
   tail->next=node;tail=tail->next;
   if(node->next)pq.push(node->next);
  }
  tail->next=nullptr;return dummy.next;
 }
};