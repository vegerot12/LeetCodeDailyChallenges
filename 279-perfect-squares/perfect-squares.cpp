class Solution {
public:
// O(n * sqrt(n))
    int numSquares(int n) {


        int sqrCnt = (int)sqrt(n)+1;
        vector<int> sqr; 
        // /(sqrCnt)

        // n is the total amt we need to make
        vector<int> dp(n+1, n+1);
        dp[0] = 0;

// these are our coins 
        for(int i =0;i<sqrCnt;i++){ 
            sqr.push_back(i*i);
        }

        // amt
        for(int i = 1;i<=n;i++){
            // coins starts from 1 as first 0 is not a real coin
            for(int j = 1;j<sqrCnt;j++){
                if(i>=sqr[j]){
                    dp[i] = min(dp[i], dp[i-sqr[j]]+1);
                }
            }
        }
        return dp[n];
    }
};