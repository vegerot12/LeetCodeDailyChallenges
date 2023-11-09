class Trie{
    public:
    Trie* child[26];
    bool isEnd;
};


 
     
class WordDictionary {
public:

  Trie* root = new Trie();
    bool search(Trie* root, int ind, string& w) {
        for(int i = ind;i<w.size();i++){
            if(w[i] != '.'){
                if(!root->child[w[i]-'a']) return false;
                root = root->child[w[i]-'a'];
            }
            else{
                for(char c = 'a' ; c<='z';c++){
                    if(root->child[c-'a']){
                       if( search(root->child[c-'a'], i+1, w)) return true;
                    }

                }
                // if not returned true at the end of all 26 chars at . tjen false
                return false;
            }
        }
        return root->isEnd;
    }

    
    void addWord(string w) {
         Trie* p = root;
           for(auto& c: w){
               if(!p->child[c-'a'])
               p->child[c-'a'] = new Trie();
               p=p->child[c-'a'];
           }
           p->isEnd = true;
    }
    
    bool search(string word) {
        return search(root,0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */