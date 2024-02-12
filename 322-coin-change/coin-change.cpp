class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       
        int n = coins.size();
        

        vector<int> dp(amount+1, amount+1);

        dp[0] = 0;

        for(int i =0;i<n;i++){
            for(int t = 1;t<=amount ; t++){
                if(t>=coins[i])
                dp[t] = min(dp[t], dp[t-coins[i]]+1);
            }
        }

        return dp[amount] < amount+1 ? dp[amount]:-1 ;
    }
};

