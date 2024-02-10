class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n+1, vector<int>(m+1,0));

        if(grid[0][0] == 1) return 0;
        res[0][1] = 1;
        // res[1][0] = 1;


        for(int i = 1;i<=n; i ++){
            for(int j =1;j<=m;j++){
                if(grid[i-1][j-1] !=1){
                    res[i][j] = res[i-1][j] + res[i][j-1];
                }
            }
        }

        return res[n][m];

    }
};