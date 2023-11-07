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
    ListNode* getMid(ListNode* head) {
 if(!head  || !head->next) return head;
        ListNode* fast = head, *slow = head;

        while(fast and fast->next and fast->next->next){
            fast = fast -> next -> next;
            slow = slow -> next;

        }

        return slow ;
    } 

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* res, *dummy = new ListNode(0);
        res = dummy;

        while(l1 && l2){
            if(l1 -> val < l2-> val){
                res-> next = l1;
                l1  = l1-> next;
            }
            else {
                res-> next = l2;
                l2  = l2-> next;
            }
            res = res-> next;
        }

        if(l1) res -> next = l1;
        if(l2) res -> next = l2;

        return dummy -> next;
        // ListNode* res = new ListNode(0);
        // ListNode* dummy = res; 
        // while(first && second){
        //     if(first -> val < second -> val){
        //         dummy->next = first ;
        //         first = first->next;
                
        //     }
        //     else{
        //         dummy->next = second ;
        //         second = second -> next;
                
        //     }
        //     dummy = dummy -> next;
        // }

        // if(first)
        // dummy -> next = first;

        // if(second)
        // dummy -> next = second;

        // return res-> next;
    }
    ListNode* sortList(ListNode* head) {
                if(!head  || !head->next) return head;


        ListNode* middle = getMid(head);
        ListNode* sec = middle->next;
        middle->next = NULL;

        return merge(sortList(head), sortList(sec));
    }
};