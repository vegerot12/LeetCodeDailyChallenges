class TrieNode{
    public:
    bool isWord = false;
    TrieNode* child[26];
};

class WordDictionary {
    private:
    
    
    bool searchWord(TrieNode* r, int index, string &word){
        for(int ind = index;ind< word.size(); ind++){
           char c = word[ind];
           if(c!='.'){
            if(!r->child[c-'a'])
            return false;
            r = r->child[c-'a'];
          }
          else{
              for(int i=0;i<26;i++){
                  /// . matches each non null child
                  if(r->child[i]){
                    //    r = r->child[i];
                       if(searchWord(r->child[i], ind+1, word))
                       return true;
                  }
                 
              }
              return false;
          
        }

    }
        return r->isWord;
    }
public:
    TrieNode *root ;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *r = root ;
        for(auto &c:word){
            if(!r->child[c-'a'])
            r->child[c-'a'] = new TrieNode();
            r = r->child[c-'a'];

        }
        r->isWord = true;
    }
    
    bool search(string word) {
         TrieNode *r = root ;
         return searchWord(r,0,word);

        }
      
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */