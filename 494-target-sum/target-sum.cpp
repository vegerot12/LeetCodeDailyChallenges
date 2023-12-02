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
    int findTargetSumWaysMemo(vector<int>& nums, int target) {
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum+= nums[i];
        }
        vector<vector<int>> dp(nums.size(), vector<int>( 2*sum+1, INT_MIN));

        return findSum(nums, target,sum, dp, 0,0);
    }

      int findTargetSumWays(vector<int>& nums, int target) {
int tot = 0;
        for(int i =0;i<nums.size();i++){
            tot+= nums[i];
        }

        if(abs(target) > tot) return 0;

        vector<vector<int>> dp(nums.size(), vector<int>( 2*tot+1, 0));

        dp[0][tot + nums[0]] += 1;
        dp[0][tot - nums[0]]  += 1;

        for(int i = 1; i<nums.size();i++){
            
            for(int j = -tot;j<=tot ; j++){
                if(dp[i-1][j+tot] > 0){
                    dp[i][tot + j+ nums[i]] += dp[i-1][tot+j];
                    dp[i][tot + j- nums[i]] += dp[i-1][tot+j];

                }
            }
        }

return dp[nums.size()-1][target+tot] ;
      }
};