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
    private: 
    ListNode* getMid(ListNode* head){
    if(!head  || !head->next) return head;

       ListNode* slow=head, *fast=head; // to be tested 
      // we check fast->next->next also because we need the node prev to mid so that node-> next is mid and we can also break link using node->next = null 
       while(fast && fast->next && fast->next->next){
           slow = slow->next;
           fast = fast->next->next;
           
       }
     
       return slow;

    }

    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* res = new ListNode(0);
        ListNode* dummy = res; 
        while(first && second){
            if(first -> val < second -> val){
                dummy->next = first ;
                first = first->next;
                
            }
            else{
                dummy->next = second ;
                second = second -> next;
                
            }
            dummy = dummy -> next;
        }

        if(first)
        dummy -> next = first;

        if(second)
        dummy -> next = second;

        return res-> next;

    }
public:
    // Merge sort
        // keep splitting the list to half recursively until single ele left 
        // keep merging now recursively 
    ListNode* sortList(ListNode* head) {
        if(!head  || !head->next) return head;

    ListNode* mid = getMid(head);
    ListNode* secondList = mid->next;
    mid->next = NULL;
    return merge(sortList(head), sortList(secondList));
   
    }
};