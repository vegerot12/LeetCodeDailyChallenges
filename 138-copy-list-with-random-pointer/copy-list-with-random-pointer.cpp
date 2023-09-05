/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        
      
        
        Node* p = head;

        while(p){
            Node* cur = p->next;
         Node* nn = new Node(p->val);
         p->next = nn;

           nn->next = cur;
            p=cur;
        }
        p = head;

        while(p && p->next){
            if(p->random){
                p->next-> random = p->random->next;
            } 
            p=p->next->next;
        }



        
        Node* dummy, *copy = new Node(0);
        dummy = copy;
                p = head;


        while(p && p->next){
            copy->next = p->next;
            p->next =  p->next->next ;
         
            p = p->next;
            copy = copy->next;
        }
        return dummy->next;

    }
};