class TrieNode{
    public:
    TrieNode* child[26];
    string w;
};
class Solution {
    private:
    TrieNode* build(vector<string>& words){
        TrieNode* root = new TrieNode();

        for(auto& w: words){
            TrieNode* p = root;
            for(auto& c:w){
                if(!p->child[c-'a'])
                {
                    p->child[c-'a'] = new TrieNode();

                }
                p = p->child[c-'a'];
            }
            p->w = w;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board,int i, int j, int n, int m,  vector<string>& res, TrieNode* root){
        if(board[i][j] == '#' || !root || !root->child[board[i][j]-'a']) return ;

        char tmp =  board[i][j] ;
        board[i][j] = '#';
        
        root = root->child[tmp-'a'];
        if(root->w.size()>0){
            res.push_back(root->w);
            root->w ="";
        } 
       

        if(i+1<n ) dfs(board, i+1, j, n,m, res,root);
        if(j+1<m ) dfs(board, i, j+1, n,m, res,root);
        if(i-1>=0) dfs(board, i-1, j, n,m, res,root);
        if(j-1>=0) dfs(board, i, j-1, n,m, res,root);

        board[i][j] = tmp;


    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = build(words);
        vector<string> res;

        int n = board.size(), m = board[0].size();

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                dfs(board, i, j, n, m, res, root);
            }
        }
        return res;
    }
};