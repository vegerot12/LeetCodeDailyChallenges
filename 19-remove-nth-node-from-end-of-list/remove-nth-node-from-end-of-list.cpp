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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast= head, *slow=head;
   
        while(fast and n--){
            fast = fast->next;
        }

        if(fast == NULL) return head->next;

        while(fast and fast->next){
            slow= slow->next;
            fast = fast-> next;
        }
cout<<slow->val;
        ListNode* tmp = slow -> next;
        slow->next = tmp->next;
        delete(tmp);

        return head;


    }
};