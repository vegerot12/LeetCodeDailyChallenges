class Trie{
    public:
    Trie* child[26];
    bool isEnd;
};

class Solution {
public:
   Trie* buildTrie(vector<string>& words){
       Trie* root = new Trie();

       for(auto w:words){
           Trie* p = root;
           for(auto& c: w){
               if(!p->child[c-'a'])
               p->child[c-'a'] = new Trie();
               p=p->child[c-'a'];
           }
           p->isEnd = true;
       }
       return root;
   }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* root = buildTrie(wordDict);
        int n = s.size();

        vector<bool> dp(n+1);
        dp[0] = true;

        for(int i=0;i<n;i++){
            if(!dp[i]) continue;
            Trie* p = root;
            for(int j = i;j<n;j++){
                if(!p->child[s[j]-'a']) break;
                p = p->child[s[j]-'a'];
                if(p->isEnd) {
                    dp[j+1] = true;
                }

                
            }
        }
        return dp[n];
    }
};