class Node{
    public:
    Node* left = NULL;
    Node* right = NULL;
    int val;
    int key;

    Node(int k, int x){
        val = x;
        key = k;
    }



};
class LRUCache {

public:
    unordered_map<int, Node*> m; // key, node
    Node* head = new Node(0,0), *tail= new Node(0,0);
    
    int cap = 0;

    void insertAtHead(int key, int val){
        Node* nn = new Node(key, val); 
        Node* tmp = head -> right;
        head -> right = nn;
        nn -> right = tmp;
        nn -> left = head;
        tmp -> left = nn;
        m[key] = nn; 
        
    }

    void remove(int key){
        
       Node* rn = m[key];
       rn -> left -> right = rn -> right;
       rn -> right -> left = rn -> left;
       delete(rn);
       m.erase(key);
        
    }

    void insert(int key, int val){

        if(m.find(key) == m.end()){
            if(m.size() >= cap){
                remove(tail->left->key);                
            }
            insertAtHead(key, val);

        }
        else{
            remove(key);
            insertAtHead(key, val);
        }
    }


    LRUCache(int capacity) {
        cap = capacity;
        head -> right = tail;
    tail -> left = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;

        int val = m[key]->val;
        remove(key);
        insertAtHead(key,val);
        return val;
    }
    
    void put(int key, int value) {
        insert(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */