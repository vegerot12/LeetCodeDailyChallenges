class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> res(m,0);
        if(grid[0][0] == 1 ) return 0;
         // if any 0 rest all should be 0 since no way to reach

// FIRST ROW INITIALISATION
        for(int col =0 ;col <m ;col++){
            if(grid[0][col] == 0) res[col] = 1;
            else break;
        }

        for(int i =1;i<n;i++){
            bool atleastOnePathFound = false;
            // FIRST COL INITIALSIATION IN EVERY ROW 
            if(grid[i][0] == 1) res[0] = 0; 
            else atleastOnePathFound = true; 

            for(int j = 1; j<m ;j++){
                if(grid[i][j] == 0){
                    atleastOnePathFound = true;
                    res[j] += res[j-1]; 
                }else res[j] = 0 ; // if current is an obstacle this cell is 0
            }

            if(!atleastOnePathFound) return 0; 
        }

        return res[m-1];
    }
};