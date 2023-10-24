/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHeader = new ListNode(-1);
        dummyHeader -> next = head;

        int tot = 0;
        
      

        ListNode* preHead, *curHead;
        preHead = dummyHeader, curHead = head;

        ListNode* cur = curHead;
        ListNode* pre = preHead;


        while(cur!=NULL){
              tot++;
              cur=cur->next;
        }

        while(tot>=k){
        int cnt = 1;
        cur = curHead;
        pre = preHead;
        ListNode* next;

            while(cnt<=k && next!=NULL){
                next = cur->next;
                cur-> next = pre;
                pre = cur;
                cur = next;
                cnt++;
            }

            preHead -> next = pre; // to map the node before head to the cur reversed head of groip
            curHead -> next = cur; // to map the cur last node of the group to the next node outside the grp

            preHead = curHead;
            curHead = cur; 
            tot-= k;

        }
        return dummyHeader->next;
    }
};