class Solution {
public:
    int dfs(vector<int>& nums, int l, int r,vector<vector<int>>& dp ){
        if(l>r) return 0;
        if(dp[l][r]) return dp[l][r];

        int cost = 0;

        for(int i=l; i<=r;i++ ){ // each of these from l to r as the first balloon
        cost =0;
        cost += nums[l-1] * nums[i] * nums[r+1]; // first cost when we take ith balloon we also take the cost of left and right boundaries 

        // now take the cost of intermediates lying from l to i-1 and i+1 to r 
        // we consider each of one those intermediate items as first shot so we do dfs over the range 
        cost += dfs(nums,l,i-1,dp) + dfs(nums, i+1,r,dp);
         dp[l][r] = max(dp[l][r], cost); // find the maximal of cost among that and put in our dp 
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        return dfs(nums, 1,n-2,dp);
    }
};