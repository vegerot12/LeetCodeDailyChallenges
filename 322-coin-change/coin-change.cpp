class Solution {
public:
    int findCoin(vector<int>& coins, int amount,
    // int cur, 
    int ind,
     vector<vector<int>>& dp
    ){
        if(ind >= coins.size() || amount <= 0){
           return amount == 0 ? 0:INT_MAX-1;
            
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        int notTaken = findCoin(coins,amount ,ind+1, dp);
        int taken = INT_MAX;

        if(amount >= coins[ind] ){
            taken = 1 + findCoin(coins, amount - coins[ind], ind, dp);
        }

        return dp[ind][amount] =  min(taken, notTaken);

        
        
    }
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        
       int res = findCoin(coins,amount, 0,dp);
        return res == INT_MAX - 1 ? -1 : res;
    }
};