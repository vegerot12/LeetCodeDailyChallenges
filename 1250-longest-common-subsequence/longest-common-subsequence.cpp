class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n1 = t1.size(), n2 = t2.size();
        vector<int> dp(n2+1,0);

        dp[0] = 0;
        int topLeft = 0;

        for(int i = 1;i<=n1;i++){
            topLeft=0;
            for(int j = 1;j<= n2 ;j++){
                int topLeftTmp = dp[j];
                if(t1[i-1] == t2[j-1]) dp[j] = topLeft +1 ;
                else dp[j] = max(dp[j], dp[j-1]);
                topLeft = topLeftTmp;
            }
        }
        return dp[n2];
    }
};