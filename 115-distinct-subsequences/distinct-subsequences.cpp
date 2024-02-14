class Solution {
public:

    int findMatch(string &s, string &t, int i, int j, vector<vector<int>> &dp ){
        if(j == 0) return dp[i][j] = 1;
         if(i<j || i==0) return dp[i][j] =  0;

        if(dp[i][j]>=0) return dp[i][j];

        
        dp[i][j] = findMatch(s,t,i-1,j,dp) ; // move str alone
        if(s[i-1] == t[j-1])
        dp[i][j] =  dp[i][j] + findMatch(s,t,i-1,j-1,dp); // move str alone + move both str and pat

        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        return findMatch(s,t,n,m,dp);
    }
};