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
        if(!head) return head;
        int tot = 0;

        ListNode* cur = head;

        while(cur){
            cur = cur-> next;
            tot++;
        }

        ListNode* dummyH = new ListNode();
        dummyH -> next = head;
        ListNode *curH = head,*preH = dummyH, *pre,*next;
        cur = head;
        while(tot>=k){
            int cnt  =0;
            cur = curH;
            pre = preH;
            while(cnt < k && next != NULL){
             next = cur -> next;
                cur -> next = pre;
                pre = cur;
                cur = next;
                cnt ++ ;
            }
            preH -> next = pre;
            curH -> next = cur;
            preH = curH;
            curH = cur;
            tot -= k;

        }
        return dummyH -> next;
    }
};