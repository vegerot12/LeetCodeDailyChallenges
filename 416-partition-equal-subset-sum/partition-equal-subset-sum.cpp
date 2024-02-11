class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i =0;i< nums.size();i++){
            sum += nums[i];
        }

        if(sum%2) return false;
        sum = sum/2;
        int n = nums.size();

        vector<bool> dp(sum+1, false);

        dp[0]= true; // initialise target 0 is true 
        for(int i = 0;i<n;i++){
            for(int j =sum ; j>= nums[i];j--){
                // sum starting from sum upto nums [i] as j , nums[i] can corntirbute to j less than that 
               
                dp[j] = dp[j-nums[i]] || dp[j];
                
            }
          

        }
        return dp[sum]; 
    }
};