// DFS
// class Solution {
    
//     private:
//     void dfs(vector<vector<char>>& grid, int i, int j){
//         if( min(i,j) < 0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0') return ;
//         grid[i][j] = '0';
//         dfs(grid, i+1,j); 
//         dfs(grid, i-1,j); 
//         dfs(grid, i,j+1); 
//         dfs(grid, i,j-1); 

//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int r = grid.size(),c= grid[0].size();
//         int cnt =0;
//         for(int i=0;i<r;i++){
//             for(int j=0;j<c;j++){
//                 if(grid[i][j] == '1'){
//                     cnt++;
//                     dfs(grid,i,j);
//                 }
//             }
//         }
//         return cnt;
//     }
// };

// BFS
class Solution {
public: // BFS , TC O(N*M) and SC = O(MN) 
    // if we dont change visited then O(n2 * m2) 
    // iterate through amtric and keep pushing 1s into bfs queue after marking them as 0(visitied)
    // and keep popping from queue to do bfs 

    // so for every node on finding a 1 we first traverse all its neighborus using bfs queue and comes back to the for loop again 
    int numIslands(vector<vector<char>>& grid) {
    int count =0;
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> q;
        int offsets[5] = {0,1,0,-1,0}; // neightbour index
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){ // if land then inc count
                    count++;
                    grid[i][j] ='0'; // mark as visited
                    q.push({i,j}); // push in queue to check neighbors
                    while(!q.empty()){
                        auto p = q.front();
                        q.pop();
                        int x = p[0];
                        int y = p[1];
                       
                        // check neighnor for land
                        for(int k =0;k<4;k++){
                            x= p[0]+offsets[k];
                            y = p[1]+offsets[k+1];
                            // if land found mark visited and push in queue
                            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='1'){
                                 grid[x][y] ='0';
                                q.push({x,y});
                            }
                                
                        }
                    }
                }
                    
            }
           
        }
       return count;
        
    }
};



