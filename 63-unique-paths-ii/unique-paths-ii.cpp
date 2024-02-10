class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        /*
         // approach 1 - O(m*n) time and space O(m*n)
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        // padded one more row and col
        // actual grid starts from 0,1 so 
        if(obstacleGrid[0][0]==1) return 0;
        dp[0][1] = 1; // if first cell is 0 it is valid

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(obstacleGrid[i-1][j-1]!=1)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n][m];
        */
    
         // approach 2 - O(m*n) time and space O(m) 
         // we need top and left - left  and top is same as dp until it is updated
        vector<int> dp(m,0);
        
       if(obstacleGrid[0][0]==1) return 0;
        // if first cell is 0 it is valid
        // if we see a 0 in first row then after that all are 0s so break
        for(int i=0;i<m;i++){
           if(obstacleGrid[0][i]==0){
              dp[i] = 1;
           }
           else break;
        }
      //There are some cases that the loop can be terminated earlier. Suppose obstacleGrid = [[0, 0, 0, 0], [1, 1, 1, 1], [0, 1, 0, 0]], then we can see that it is impossible to reach the bottom-right corner after updating the second row since second row fully 1
    
    // we alrd traversed row 0 and updted dp so start with 1st row
    for(int i=1;i<n;i++){ 
        bool foundPath = false; // to mark if we found atleast 1 way in each row
        // handle 0th column
        if(obstacleGrid[i][0]) dp[0] = 0; // obs in 0 column
        else foundPath = true; // found a path in 0th column
        // traverse columsns 1 to m-1
        for(int j=1;j<m;j++){
            if(obstacleGrid[i][j] == 0){ // if we found a way 
             dp[j] += dp[j-1]; // dp[j] will have prev  ie dp[i-1][j] before updating and dp[j-1] has left column val
             foundPath = true; // mark true since we found atleast one way
            }else
            dp[j] = 0; // if cur is a obstcle , this cell leads to no path so 0
            
        }
        if(!foundPath) return 0;

    }
    return dp[m-1];
        
    }
};