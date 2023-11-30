class Solution {
public:
void dfs(vector<int>& nums, int ind,vector<vector<int>>& res,
        vector<int>& tmp, int target){
            if(target == 0){
        res.push_back(tmp);
    return ;
            }
        if(ind == nums.size()) return;
//  our main intention is to make sure we dont include same ele in any given subsets from level so we do nums[i] == nums[i-1] continue . But we also want to include it in different subset even if nums[i] == nums[i-1] they can be very well part of different subsets from different level of recursion, and if we use this condiiton alone then we may not be able to use them in next subset also so to restrict or channelise this condition properly we also check if i != ind  and nums[i] == nums[i-1] continue which means that if i==ind we are starting a new level and we should ignore about nums[i] == nums[i-1] .
        for(int i=ind;i<nums.size();i++){
             if(i != ind && nums[i]==nums[i-1]) continue;
             if(nums[i] <= target){

            tmp.push_back(nums[i]);
            target -= nums[i];
            dfs(nums,i+1, res, tmp, target);
            tmp.pop_back();
            target += nums[i];

             }
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(nums,0, res,tmp, target);
        return res;
    }
};
