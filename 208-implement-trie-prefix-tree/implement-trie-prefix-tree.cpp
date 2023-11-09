class TrieNode{
    public:
    TrieNode* child[26];
    bool isEnd ;
    
};

class Trie {
public:
    TrieNode* root ;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *p = root;
        for(auto c:word){
            if(!p->child[c-'a'] )
            p->child[c-'a'] = new TrieNode();
            p =  p->child[c-'a'] ;
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *p = root;
        for(auto c:word){
            if(!p->child[c-'a'] )
           return false;
            p =  p->child[c-'a'] ;
        }
        return p->isEnd ;
    
    }
    
    bool startsWith(string prefix) {
               TrieNode *p = root;

        for(auto c:prefix){
            if(!p->child[c-'a'] )
            return false;
            p =  p->child[c-'a'] ;
        }
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */