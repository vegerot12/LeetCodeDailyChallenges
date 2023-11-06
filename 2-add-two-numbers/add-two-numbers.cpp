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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        // ListNode *dummyHeader =  new ListNode(0), *res = dummyHeader;
        ListNode* p2=l2;
        while(l1-> next && l2->next ){
            
                carry += l1->val+l2->val;
            
                l2 -> val = carry%10;
                carry = carry/10;
                l1 = l1->next;
                l2 = l2->next;
            
            
        }
// if l2 is only there then no issues, we are anyways gonna return l2 directly 
        while(carry || l1){
            carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            l2 -> val = carry%10;
                carry = carry/10;

         if (l1) l1 = l1 -> next;
// in case if l2 is done and there is still carry or nodes in l1 then we create new ndoes in l2 , move l2 ptr to that and be ready for next iteration 
         if(!l2 -> next && (carry || l1)){
             l2 -> next  = new ListNode();
         }
         l2 = l2-> next;

        }

        return p2;
    }
};