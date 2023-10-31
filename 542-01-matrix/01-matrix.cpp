class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int offset[5] = {0,1,0,-1,0};

        int n = matrix.size(),m= matrix[0].size();

        queue<pair<int,int>> q;
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(matrix[i][j] == 0)
                q.push({i,j});
                else 
                matrix[i][j] = -1;
            }
        }
int dis = 0;

        while(!q.empty()){
           int s = q.size();
           while(s--){
            auto p = q.front();
            q.pop();

            for(int k = 0 ; k< 4;k++){
                int x = offset[k] + p.first;
                int y = offset[k+1] + p.second;
                if(x>=0 and x<n and y>=0 and y<m and matrix[x][y] == -1){
                   
                    matrix[x][y] = dis+1;

                    q.push({x,y});

                }
            } 
           }
           dis++;



        }
        return matrix;
    }
};