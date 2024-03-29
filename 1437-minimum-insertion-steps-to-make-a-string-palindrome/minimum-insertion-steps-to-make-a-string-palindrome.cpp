class Solution {
    int lcs(string& s, string &t, int &n){
        vector<vector<int>> dp(n+1,vector<int>(n+1, 0));

        for(int i = 1;i <=n; i++){
             for(int j=1; j<=n ;j++){
                 if(s[i-1] == t[j-1]) 
                 dp[i][j] = 1+ dp[i-1][j-1];
                 else
                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
             }
        }
        return dp[n][n];

    }
    int lcsSpaceOptim(string& s, string &t, int &n){
        vector<int> dp(n+1, 0), cur(n+1,0);

        for(int i = 1;i <=n; i++){
             for(int j=1; j<=n ;j++){
                 if(s[i-1] == t[j-1]) 
                 cur[j] = 1 + dp[j-1]; // j-1 alrd updated in cur row 
                 else
                 cur[j] = max(dp[j], cur[j-1]); // j-1 updated so its same as i,j-1 and j not updated so its i-1,j
             }
             dp=cur;
        }
        return dp[n];

    }
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        return n - lcsSpaceOptim(s,t,n);
    }
};