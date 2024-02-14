class Solution {
public:
    int minDistance(string w1, string w2) {
        int n = w1.size(), m = w2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1, 0));
        
        //         // in row 0. w1 is empty so we need to add so cost = index 

                    for(int j =0;j<=m;j++){
                        dp[0][j] = j; // if we are adding j charss so j 

                    }

        

        for(int i =1;i<=n;i++){
            // col 0 is empty so w2 is emp so we need to remve from w1 
            dp[i][0] = i; // if we are removing i chars 
            for(int j =1;j<=m;j++){
                if(w1[i-1] != w2[j-1]){
                    dp[i][j] = 1 + min( {
                        dp[i-1][j-1] , // replace
                        dp[i][j-1], // remove str w2
                        dp[i-1][j] // move char at str w1
                    });
                }
                else{
                     dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};