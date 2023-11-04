class Solution {
public:
    void find(vector<int>& nums, int ind, vector<int>& cur,vector<vector<int>>& res){
        res.push_back(cur);
        
        if(ind == nums.size()) {
        return;

        }

        for(int i =ind;i<nums.size();i++){
            cur.push_back(nums[i]);
            find(nums,i+1, cur, res);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;

        find(nums, 0, cur, res);
        return res;
    }
};