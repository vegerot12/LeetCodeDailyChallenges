class Solution {
public:
    void perm(int ind,vector<int>& nums,vector<vector<int>>& res ){
        if(ind == nums.size()) {
            res.push_back(nums);
        }

        for(int i = ind;i<nums.size();i++){
            swap(nums[i], nums[ind]);
            perm(ind+1, nums,res);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        perm(0,nums,res);
        return res;
        
    }
};