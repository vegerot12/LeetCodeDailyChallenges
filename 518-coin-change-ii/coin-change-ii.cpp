class Solution {
public:
    int findSum( vector<int>& coins, int ind, int amount, vector<vector<int>>& memo ){
        if(ind == coins.size()) {
            if(amount == 0) return 1;
            return 0;
        }

        if(memo[ind][amount]!=0) return memo[ind][amount]; 

        int notTaken = findSum(coins, ind+1, amount, memo);
        int taken = 0;

        if(amount >= coins[ind])
        taken = findSum(coins, ind, amount-coins[ind], memo);

        return memo[ind][amount]= taken + notTaken;
    }
    int changeMemo(int amount, vector<int>& coins) {
        int n = coins.size();

         vector<vector<int>> memo(n, vector<int> (amount+1,0));

        return findSum(coins, 0,amount,memo);

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

     vector<int> dp(amount+1,0);

     dp[0] =1 ; // 1 way to make 0 amt 

     for(int i =0;i<n;i++){
         for(int j = 0;j<=amount;j++){
             if(j>=coins[i]){
                 dp[j]  +=  dp[j-coins[i]];
             }
         }
     }

        return dp[amount]  ;

    }
};