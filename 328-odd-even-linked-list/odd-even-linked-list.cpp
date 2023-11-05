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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next ) return head;
        ListNode* odd = head, *even = head->next, *eh = even;


        while(odd->next and even->next){
            ListNode* on = odd->next;
            ListNode* en = even ->next;
            odd -> next = on ? on->next: NULL;
            even-> next = en ? en -> next : NULL;
            odd  = odd->next;
            even = even -> next;
        }

        odd->next = eh;
        return head;
    }
};