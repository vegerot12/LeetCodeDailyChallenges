class Solution {
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j){
        // if grid2 is 0 it doesnt matter at all so it can still be a subisland of grid1 if grid2 is zero
        if(i<0 or  i>= grid1.size() or j>= grid1[0].size() or grid2[i][j]==0) return true;
       
     // if grid 2 alrd visited or if its 0 return back

        // if grid[2] is 1 then we need to chck if grid[1] is 0 if so grid2 cant be sub island of grid1 so
        if(grid1[i][j]==0) return false;
        grid2[i][j]=0; // mark as visit 
         bool d=dfs(grid1, grid2,i-1,j);
         bool u=dfs(grid1, grid2,i+1,j);
         bool rt=dfs(grid1, grid2,i,j+1);
   bool l=dfs(grid1, grid2,i,j-1);
            return l&&rt&&d&&u; 
        // return (dfs(grid1,grid2,i-1,j) && dfs(grid1,grid2,i+1,j) && dfs(grid1,grid2,i,j+1) && dfs(grid1,grid2,i,j-1));


    }

// public:
//     int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
//         int r = grid1.size(), c = grid1[0].size(), res=0;
//         for(int i=0;i<r;i++){
//             for(int j=0;j<c;j++){
//                 if(grid2[i][j] == 1)
//                 if(dfs(grid1,grid2, i, j)) res++;
            
//             }
//         }
//         return res;
//     }
public:
//  bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i,int j){
//         if(i>=grid1.size() || i<0 || j>=grid1[0].size() || j<0 || grid2[i][j] !=1) return true; // if grid 2 alrd visited or if its 0 return back
        
//         // o in grid1 in the same cell where it was 1 in grid2 so false
//         if( grid1[i][j]==0) return false;  
        
//         grid2[i][j] = -1; // mark as visited
//             // check its adjacen cells to find the sub island in grid2 in grid1
//         bool l=dfs(grid1, grid2,i,j-1);
//          bool rt=dfs(grid1, grid2,i,j+1);
//          bool d=dfs(grid1, grid2,i-1,j);
//          bool u=dfs(grid1, grid2,i+1,j);
//             return l&&rt&&d&&u; 
//     }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int r = grid1.size();
        int c = grid1[0].size();
        int m = 0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid2[i][j] == 1) // we saw 1 in grid 2 so we check if we have one on grid1 in the same cell 
                {
                    if(dfs(grid1,grid2,i,j))
                        m++;
                }
            }
        }
        return m;
    }
};