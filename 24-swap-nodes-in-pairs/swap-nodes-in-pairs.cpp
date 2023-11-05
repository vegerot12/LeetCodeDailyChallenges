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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) return head;

       ListNode* cur = head, *prev = NULL, *next = head -> next;
       head = head -> next;
// 1 2 3 4
//pc n 
       while(cur and next){
           if(prev){
               prev -> next = cur->next;  // in iter 2 , 1->4
           }

           
           cur -> next = next->next;  // 1->3
           next -> next = cur; // 2->1
           prev = cur; //  pre = 1
           cur = cur->next; // cur = 3.      

           if(cur){
              next = cur->next ; // next = 4 
           } // 2 1 3 4
             //   p c n

       }
       return head;
    }
};