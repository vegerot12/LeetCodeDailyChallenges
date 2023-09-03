class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size(), c= grid[0].size();
        int res = 0;

        for(int i =0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    res += 4;
                    if(i>0 && grid[i-1][j] ==1)
                    res -=2;
                    if(j>0 && grid[i][j-1] ==1)
                    res-=2;
                }
            }
        }
        return res;
    }
};