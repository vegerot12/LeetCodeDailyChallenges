class Solution {
    int offset[5] = {0,1,0,-1,0};
    void dfs(int i,int j,vector<vector<bool>>& curVis,vector<vector<bool>>& otherVis,vector<vector<int>>& heights,vector<vector<int>>& res){
        // if(i<0 or j<0 or i>= heights.size() or j>= heights[0].size()) return ;

        if(curVis[i][j]) return;

        curVis[i][j] = true;

        if(otherVis[i][j]) {
            res.push_back({i,j});

        }

        for(int k = 0; k<4;k++){
            int x = i + offset[k];
            int y = j + offset[k+1];

            if(x<0 or y<0 or x>= heights.size() or y>= heights[0].size() or heights[i][j] > heights[x][y]) continue;
            
            dfs(x,y,curVis,otherVis,heights,res); 

            

        }


    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;

        int n = heights.size(), m = heights[0].size();

        vector<vector<bool>> atl(n, vector<bool>(m, false)), pac(n, vector<bool>(m, false));

        for(int i =0;i<m;i++)  // col changes
        {
            dfs(0,i, pac,atl, heights, res); // top and left pac
            dfs(n-1,i, atl,pac, heights, res); // bottom and right atl
        }

         for(int i =0;i<n;i++) // row changes 
        {
            dfs(i,0, pac,atl, heights, res); // top and left pac
            dfs(i,m-1,  atl,pac, heights, res); // bottom and right atl
        }

        return res;

    }
};