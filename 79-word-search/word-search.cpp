class Solution {
public:

    int offset[5] = { 0,1,0,-1,0};

    bool dfs(vector<vector<char>>& board,int i, int j, string word, int ind){
        if(ind == word.size()) return true;
        if( i<0 || i>=board.size() || j<0 || j>= board[0].size()) return false;


        if(word[ind]!= board[i][j] ||  board[i][j] == '#') return false;

        char tmp = board[i][j];
        board[i][j] = '#';

        for(int k =0;k<4;k++){
            int x = i + offset[k];
            int y = j + offset[k+1];

            // if(x>=0 and x<board.size() and y>=0 and y< board[0].size() and board[x][y] != '#'){
                if(dfs(board, x,y, word, ind+1)) return true;
            // }

        }

        board[i][j] = tmp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }
};