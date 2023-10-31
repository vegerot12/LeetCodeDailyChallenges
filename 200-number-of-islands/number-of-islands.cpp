class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      int count =0;
        int n = grid.size(), m = grid[0].size();
        queue<array<int,2>> q;
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