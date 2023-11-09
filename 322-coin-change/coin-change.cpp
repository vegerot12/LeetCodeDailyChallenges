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
    int coinChangeMemoisation(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        
       int res = findCoin(coins,amount, 0,dp);
        return res == INT_MAX - 1 ? -1 : res;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp( amount+1, amount+1);

       
        dp[0] = 0;
        
       for(int i = 1;i<=coins.size() ;i++){
           for(int j =1;j<=amount;j++){
               if(j >= coins[i-1])
               dp[j]= min(1+dp[j-coins[i-1]] , dp[j]) ;
           }
       }
       return dp[amount] > amount ? -1 : dp[amount];

    //    vector<int> dp(amount+1, amount+1);
    //     dp[0] =0;
    //   for(int i=1;i<=coins.size();i++){
    //       for(int j=1;j<=amount;j++){
    //           if(j>=coins[i-1]){
    //               dp[j] = min(dp[j], dp[j-coins[i-1]]+1);
    //           }
    //       }
    //   }
    //   return dp[amount] > amount ? -1 : dp[amount];
    }

    
};