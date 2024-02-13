class Solution {
public:
    int longestCommonSubsequence(string &s, string &t){
        int n = s.size(), m = t.size();

        vector<int> dp(m+1,0) , cur(m+1,0);
        int res  =0;

        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    cur[j] = 1 + dp[j-1];
                    // res = max(res, cur[j]);
                }
                else cur[j] = max(dp[j], cur[j-1]);
            }
            dp = cur;
        }
        return dp[m];
    }
    int minDistance(string word1, string word2) {
        int tot = word1.size() + word2.size();
        return tot - 2*(longestCommonSubsequence(word1, word2));
     }
};