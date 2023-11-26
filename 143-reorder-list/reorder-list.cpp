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

    ListNode* getMid(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* fast = head, *slow = head;

        while(fast and fast->next){
            slow = slow->next;
            fast = fast -> next -> next;

        }

        return slow;

    }

    ListNode* reverse(ListNode* head){
        if(!head) return head;

        ListNode* cur=head, *pre = NULL, *next ;

        while(cur){
            next = cur -> next;
            cur ->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        if(!head) return;

        ListNode* mid = getMid(head);
        ListNode* sec = reverse(mid);
        mid -> next = NULL;

    //    ListNode* first = head, *fn, *sn;

    //     while(first-> next and sec->next){

    //  fn=  first -> next;
    //       first -> next = sec;
    //       first = fn;
    //       sn = sec->next;
    //       sec -> next = fn;
          
    //       sec = sn;
    //     }
       ListNode* first = head, *res = new ListNode(),*dummy = res;

    while(first and sec){
        res -> next = first;
        first = first->next;
        res = res->next;
        res -> next = sec;
        sec = sec->next;
        res = res->next;


    }
res->next = nullptr; // Set the next pointer of the last node to nullptr

        
head = dummy->next;

    }
};