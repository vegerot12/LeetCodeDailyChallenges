/*
1. First push all boundary in a pq  and mark as vis
2. find least height from pq
3. visit its neighbor, 
4. if the neighbor height is larger than the boundary height then the boundary moves in and the neighbour becomes the boundary
5. else fi the neigbor height is smaller than the min boundary height then the negogbout becomes the container of water storage and the volume is calculated as the minBoundaryheight - the neighbor height 
6. push the newightbor in pq  and mark as vis
// O(M*N*3 )  as we cant go back to the cell we came from so 3 possible movements and O(M*N)
*/


class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        priority_queue< array<int,3> , vector< array<int,3>> , greater<> > pq;
        int n = height.size(), m = height[0].size(), res =0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int offsets[5] = {0,1,0,-1,0};

        // 1.
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1 || i==0 || j==m-1 || j==0){
                    pq.push({ height[i][j], i, j});
                    vis[i][j] = true;
                }
            }
        }

        //2. 
        int minBd = 0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            // 4. if cur bd is bigger than minBd update min boundary
            minBd = max(minBd, p[0]);


            for(int k=0;k<4;k++){
                int x = p[1] + offsets[k];
                int y = p[2] + offsets[k+1];
                if(x<n && x>=0 && y<m && y>=0 && !vis[x][y]){

                    // 5 
                    if( minBd > height[x][y]){
                        res+= (minBd - height[x][y]);

                    }
                    // 6
                    pq.push({height[x][y], x, y });
                    vis[x][y] = true;
                }

            }
            
        }

        
return res;
            }
};