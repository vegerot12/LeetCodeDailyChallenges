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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head; 
        int cnt =0;


        ListNode* fast = head;
        while(fast){
            cnt ++;
            fast = fast->next;
        }

        fast = head;
        k = k%cnt;

        if(k==0) return head;

        ListNode* slow= head;
        while(fast and k){
            k--;
            fast = fast -> next;
        }

        while(fast and fast ->next){
            fast = fast ->next;
            slow = slow-> next;
        }
        ListNode* newHead = slow->next;
        slow -> next = NULL;
        fast -> next = head;

        return newHead;

    }
};