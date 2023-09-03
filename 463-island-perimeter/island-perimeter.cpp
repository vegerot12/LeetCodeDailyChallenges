class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res =0, r= grid.size(), c= grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    res+= 4; // first add 4 ( assuming all 4 are water )
                    if( i>0 && grid[i-1][j] == 1 ) //  check if up is a land then subtract 2 - one for this cell's upper bundayr and one for that cells' down boundary
                    res -= 2;
 // check if left is a land then subtract 2 - one for this cell's left bundayr and one for that cells' right  boundary
                    if(j>0 && grid[i][j-1] ==1 ) res -= 2;
                }

            }
        }
        return res;
    }
};