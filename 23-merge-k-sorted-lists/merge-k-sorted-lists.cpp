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
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* dh = new ListNode(0), *res;
        res = dh;
        
        while(a && b){
            if(a->val <= b-> val){
                res -> next = a;
                a=a->next;
            }else{
                res->next = b;
                b=b->next;
            }
            res = res-> next;
        }

        if(a){
            res-> next = a;
            
        }
        if(b){
            res->next = b;
        }

        
        return dh-> next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if(lists.size()==0) return NULL;
        int len = lists.size();
        int i =0;
        while(len>1){
            for(int i =0;i<len/2;i++){
                lists[i] = merge(lists[i], lists[len-i-1] );
            }
            len = (len+1)/2;

        }
        return lists[0];
    }
};