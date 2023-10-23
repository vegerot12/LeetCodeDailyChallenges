class Solution {
public:
bool isSafe(int col,vector<string>& cur, int row, int n ){
    for(int i=row;i>=0;i--){
        if(cur[i][col]=='Q') return false;
    }

    for(int i=row, j=col; i>=0&&j<n;i--,j++){
        if(cur[i][j]=='Q') return false;
    }
     for(int i=row, j=col; i>=0&&j>=0;i--,j--){
        if(cur[i][j]=='Q') return false;
    }
    return true;
}

   void solve(vector<vector<string>>& res,  vector<string>& cur, int n , int row ){
        if(row == n){
            res.push_back(cur);
            return ;
        }

        for(int i =0;i<n;i++){ // cols
           if( isSafe(i,cur, row, n)){
               cur[row][i] = 'Q';
               solve(res, cur, n, row+1);
                  
               
               cur[row][i] = '.';
           }

        }
    }

    vector<vector<string>> solveNQueens(int n) {
       
        vector<string> cur(n,  string (n,'.'));
        vector<vector<string>> res;
        solve(res,cur, n, 0);
        return res;
    }
};