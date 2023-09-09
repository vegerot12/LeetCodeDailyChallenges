class TrieNode{
    public:
    bool isWord=false;
    TrieNode* child[26];
};
class Trie {
    private:
    TrieNode* root;
public:

    Trie() {
      root = new TrieNode();
    }
    
    void insert(string word) {
        
       
            TrieNode* curRoot = root;
            for(auto &c:word){
                if(!curRoot->child[c-'a']){
                    curRoot->child[c-'a'] = new TrieNode();

                }
                curRoot = curRoot->child[c-'a'];
            }
            curRoot->isWord = true;
        
    }
    
    bool search(string word) {
       
            TrieNode* curRoot = root;
            for(auto &c:word){
                if(curRoot->child[c-'a']==NULL){
                    return false;

                }
                curRoot = curRoot->child[c-'a'];
            }
           return curRoot->isWord ;
        
    }
    
    bool startsWith(string prefix) {
         TrieNode* curRoot = root;
            for(auto &c:prefix){
                if(curRoot->child[c-'a']==NULL){
                    return false;

                }
                curRoot = curRoot->child[c-'a'];
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