class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum  = 0;
        for(int n:nums) sum+=n;

        if(sum%2) return false;
        int n = nums.size();

        sum = sum/2;

        vector<bool> dp(sum+1,false);
        dp[0] = true;

        for(int i =0;i<n;i++) { // for each nums 

            for(int j = sum; j>=0;j--){
                if(nums[i]<= j){
                    dp[j] = dp [j] || dp[j-nums[i]];
                }
            }

        }
         return dp[sum];
        //  int sum=0;
        // for(int n:nums)
        // sum+=n;

        // if(sum%2) return false;

        // sum = sum/2;

//         vector<bool> dp(sum+1, false);
// dp[0] = true;
//         for(int i =1;i<=nums.size();i++){
//             for(int j =sum;j>=0;j--){
//                 if(j>=nums[i-1]) 
//                dp[j] = dp[j]|| dp[j-nums[i-1]];
//             }
//         }
//         return dp[sum];
    }
};