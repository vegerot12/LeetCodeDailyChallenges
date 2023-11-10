class Solution {

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1,0);

        dp[0] = 1; // for target 0 -> 1 way

        for(int j = 1; j<=target;j++ ){
            for(int n: nums){
                if(n <= j){
                    dp[j] = dp[j ] + dp[j-n];

                }
            }
        }
        return dp[target];

    }
        
};
   