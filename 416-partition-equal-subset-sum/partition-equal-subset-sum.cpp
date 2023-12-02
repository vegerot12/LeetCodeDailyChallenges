class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        int n = nums.size();

        for(int i =0;i<n;i++) s+= nums[i];

        if(s%2) return false;

        s = s/2;

        vector<bool> dp(s+1,false);
        dp[0] = true;

        for(int i =0;i<n;i++){
            for(int j=s;j>=1;j--){
                if(nums[i]<=j){
                    dp[j]=  dp[j] || dp[j-nums[i]];
                }
            }
        }

        return dp[s];
    }
};