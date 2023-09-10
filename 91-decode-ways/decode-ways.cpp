class Solution {
public:

   

    int numDecodings(string s) {
         int n = s.size();
         if(s[0] == '0') return 0; // because this is invalid
        if(s.size()<=1) return 1;
        vector<int> dp(s.size()+1, 0);
        dp[0] = dp[1] =1;

        for(int i =2;i<=n;i++){

            int oneDigit = s[i-1] -'0';
            int twoDigit =(( s[i-2] -'0') *10) + (s[i-1] -'0');

            if(oneDigit>0) dp[i] += dp[i-1];
            if(twoDigit>= 10 and twoDigit <= 26) dp[i] += dp[i-2];


        }
        return dp[n];
    }
};
