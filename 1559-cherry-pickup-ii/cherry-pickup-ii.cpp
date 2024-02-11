class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(m,0)));
        // initialise the last row for each pos of rob1 and rob2
        for(int rob1 = 0;rob1<m; rob1++){
            for(int rob2 = 0;rob2<m;rob2++){
                if(rob1 == rob2)
                dp[n-1][rob1][rob2] = grid[n-1][rob1];
                else
                dp[n-1][rob1][rob2] = grid[n-1][rob1] + grid[n-1][rob2];

            }
        }
        // last row of dp:
        // 2 3 3
        // 3 1 2
        // 3 2 1 
        // for rows n-2 to 0 

        // for each row from n-2 to 0
        for( int row = n-2; row>=0; row--){
            // for each pos of rob1 and each pos of rob2
            for(int rob1 = 0; rob1<m; rob1++){
                for(int rob2 = 0; rob2<m;rob2++){
                    int maxRow = INT_MIN;

                    // for each possible next step of each robots
                    // we are building from top to bottom so we calculate based on next step 

                    for(int nextRob1 = -1; nextRob1<=1 ; nextRob1++){
                         for(int nextRob2 = -1; nextRob2<=1 ; nextRob2++){
                             int ans = 0;

                             if(rob1 == rob2){
                                 ans = grid[row][rob1];
                             }
                             else
                                 ans = grid[row][rob1] + grid[row][rob2];

                             
                             // if next step is not feasible 
                             if(nextRob1 + rob1 <0 || nextRob1 + rob1 >=m || nextRob2 + rob2 <0 || nextRob2 + rob2 >=m)
                             ans = INT_MIN;
                             else  // if next step is feasible, we determine current based on the next step  (row+1) so far which is in dp
                             ans += dp[row+1][nextRob1 + rob1][nextRob2 + rob2 ];

                        // check if each of these poosiblity is max of that combination of robot1 and rob2  
                        maxRow = max(maxRow, ans);
                        
                    }
                }
                // after assessing all possible next steps we assign the maxRow to the dp for cur row and cur pos of rob1 and rob2
                dp[row][rob1][rob2] = maxRow;
            }
        }
        }
        // initially rob1 and rob2 are supposed to start at 0 and m-1 so we return 0th row that position
       return dp[0][0][m-1]; 
    }
};