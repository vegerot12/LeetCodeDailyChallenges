class Solution {
public:

int findSum(vector<int>& nums, int target,int sum,  vector<vector<int>> &dp, int cur, int ind){
    if(ind == nums.size()){
        if(target == cur) return 1;
        else return 0;
    }

    if(dp[ind][cur+sum] != INT_MIN) return dp[ind][cur+sum];

    int add = findSum(nums,target,sum, dp, cur+ nums[ind], ind+1);
    int sub = findSum(nums,target,sum, dp, cur- nums[ind], ind+1);

    return dp[ind][cur+sum] = add +sub;


}
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum+= nums[i];
        }
        vector<vector<int>> dp(nums.size(), vector<int>( 2*sum+1, INT_MIN));

        return findSum(nums, target,sum, dp, 0,0);
    }
};