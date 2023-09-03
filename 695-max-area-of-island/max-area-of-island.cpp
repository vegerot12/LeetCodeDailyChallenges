// O(m*n) and O(m*n) - no extra space
class Solution {
public:
    /*
    int dfs(vector<vector<int>>& grid, int i, int j, int r, int c){
        if(i>=r || i<0 || j>=c || j<0 || grid[i][j]==0) return 0;
        
        grid[i][j]=0;
        int u = dfs( grid, i-1,j,r,c);
        int d = dfs( grid, i+1,j,r,c);
        int l = dfs( grid, i,j-1,r,c);
        int ri = dfs( grid, i,j+1,r,c);
        return 1+u+d+l+ri;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if( grid.size()==0) return 0;
        int r = grid.size();
        int c = grid[0].size();
        int m = 0;
        
        for(int i =0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                  int cur = dfs( grid, i,j,r,c); 
                  m = max(m,cur);
                }
            }
        }
        return m;
    }
    */
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int m =0;
        int offsets[5] = {0,1,0,-1,0}; 
        queue<pair<int,int>> q;
        int r = grid.size(), c= grid[0].size();
        for(int i =0;i< r;i++ ){
            for(int j=0;j<c;j++){
                // as soon as we found a land do bfs and find connected neighbours and mark it all as visited 
                if(grid[i][j] == 1)
                {
                    int cnt =1;
                    m = max(cnt,m);
                    grid[i][j] =0; // mark as visit
                       q.push({i,j});
                while(!q.empty()){
                    auto p = q.front();
                    q.pop();
                    int x = p.first;
                    int y = p.second;
                    
                    // bfs
                    for(int k =0;k<4;k++)
                    {
                        if(x+offsets[k] < r &&  x+offsets[k] >= 0 && y+offsets[k+1] < c && y+offsets[k+1]>=0 && grid[x+offsets[k]][y+ offsets[k+1]] ==1)
                        {
                          grid[x+offsets[k]][y+ offsets[k+1]] =0; // mark as visit
                          q.push({x+offsets[k], y+ offsets[k+1]});
                          cnt++;
                          m = max(m, cnt);
                        }
                    }
                }
                }
            }
        }
       return m ;
    }
};