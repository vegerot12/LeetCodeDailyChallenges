class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
// find lcs 
        for(int i = 1; i<=n;i++){
            
            for(int j = 1; j <= m ; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            
        }
// cout<<dp[m]<<endl;
        int lcsLen = dp[n][m];

        int i = n , j=m, sptr = n+m - lcsLen;
        string res(sptr,'#');

        while(i>0 && j>0){
            if(s[i-1] == t[j-1]){
                res[sptr-1] = s[i-1];
                sptr--;
                i--;
                j--;
             }
             else if(dp[i-1][j]<dp[i][j-1]){ // prev row j < cur row j-1 so dec j ptr
                res[sptr-1] = t[j-1];
                sptr--;
                j--;
             }
             else{ 
                res[sptr-1] = s[i-1];
                sptr--;
                 i--;
                 }
        }

        while(i>0){
            res[sptr-1] = s[i-1];
             sptr--;
                 i--;

        }
         while(j>0){
            res[sptr-1] = t[j-1];
             sptr--;
                 j--;

        }
        return res;
    }
};