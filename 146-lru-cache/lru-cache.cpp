class Node{
    public:
    int key;
    int val;
    Node* prev=NULL,*next=NULL;

    Node(int k,int v){
        key = k;
        val = v;
    }
};
class LRUCache {
    unordered_map<int,Node*> m;
    int cap;
    Node* head=new Node(-1,-1), *tail=new Node(-1,-1);
public:
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void insertAtHead(int key,int value){
        Node* tmp = head -> next;
        Node* nn = new Node(key, value);
        head -> next = nn;
        nn -> prev = head;
        nn -> next = tmp;
        tmp -> prev = nn;
        m[key] = nn;
    }

    void removeFromLast(){
        Node* tmp = tail -> prev;
        tmp-> prev -> next = tail;
        tail -> prev = tmp -> prev;
        m.erase(tmp->key);
        delete(tmp);
    }

    int remove(int key){
        Node *tmp = m[key];
        tmp -> prev -> next = tmp -> next;
        tmp -> next -> prev = tmp -> prev;
        int val = m[key]->val;
        m.erase(key);
        delete(tmp);
        return val;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        int val = remove(key);
        insertAtHead(key,val);
        return m[key]->val;
    }
    
    void put(int key, int value) {
        if(m.find(key) == m.end()){
            if(m.size() == cap){
                removeFromLast();
            }
        }else{
            remove(key);        
        }
            insertAtHead(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */