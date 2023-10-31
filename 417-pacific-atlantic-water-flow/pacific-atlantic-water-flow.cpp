class Solution {
    int offset[5] = {0,1,0,-1,0};
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& heights,vector<vector<int>>& res, int val){
       
       
        if(vis[i][j]==val || vis[i][j]==3) return;

        vis[i][j] += val;

        if(vis[i][j]==3) {
            res.push_back({i,j});

        }

        for(int k = 0; k<4;k++){
            int x = i + offset[k];
            int y = j + offset[k+1];

            if(x<0 or y<0 or x>= heights.size() or y>= heights[0].size() or heights[i][j] > heights[x][y]) continue;
            
            dfs(x,y,vis,heights,res,val); 

            

        }


    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;

        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i =0;i<m;i++)  // col changes
        {
            dfs(0,i, vis, heights, res, 1); // top and left pac
            dfs(n-1,i,vis, heights, res, 2); // bottom and right atl
        }

         for(int i =0;i<n;i++) // row changes 
        {
            dfs(i,0,vis, heights, res, 1); // top and left pac
            dfs(i,m-1,vis, heights, res, 2); // bottom and right atl
        }

        return res;

    }
};