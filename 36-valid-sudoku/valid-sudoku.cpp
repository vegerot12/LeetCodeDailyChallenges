class Solution {
public:
    bool check( vector<vector<char>>& board, int i, int j, int n, int m){

        char val = board[i][j];
        board[i][j] = '.';
        
        for(int c =0;c<n;c++){
            if(board[i][c] == val || board[c][j] == val)  return false;
            if(board[(i/3)*3+c/3][(j/3)*3+c%3] == val) return false; 
        }
        board[i][j] = val;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
        
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] != '.')
               if (!check(board, i, j, n, m)) return false;
            }
        }

        return true;
    }
};