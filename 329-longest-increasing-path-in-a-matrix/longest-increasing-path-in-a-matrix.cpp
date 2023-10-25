class Solution {
public:
    int offset[5] = {0,1,0,-1,0};
    int dfs(int i,int j,vector<vector<int>>& matrix , vector<vector<int>>& dp){
        if(i<0 || i>=matrix.size() || j<0 || j>= matrix[0].size() ) return 0;

        if(dp[i][j] > 0) return dp[i][j];

        int len =0;
        for(int k = 0;k<4;k++){
            int x = i+offset[k], y = j+offset[k+1];
            if(x<matrix.size() && y<matrix[0].size() && x>=0 && y>=0 && matrix[i][j] < matrix[x][y]){
                len = max(len, dfs(x,y,matrix, dp));
            }
        }
        return dp[i][j] = len+1;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        int res = 0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
              res = max(res, dfs(i,j,matrix, dp));
            }
        }
        return res;
    }
};