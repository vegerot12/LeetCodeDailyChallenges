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
        // vector<vector<int>> res();
        // vector<int> cur;

        // find(nums, 0, cur, res);

        // ITERATIVE
        int n = nums.size(), p= 1<<n; // 2^n
        vector<vector<int>> res(p);

        // based on the idea that the first ele is in every two subset
        // second ele is in 2 of every four subset // third ele is in 4 out of every 8 subset 

        for(int i = 0;i<p;i++){
            for(int j=0;j<n;j++){ // to check if j th ele is in the subset 
            if((i>>j) & 1) { // check if this subset number i , say if it is 7 and j is 2 and we move 7 two places left => 111 => 001 and 1 => 1 so this 2nd ele is in 7th subset so push it 
                res[i].push_back(nums[j]);
            }

            }
        }

        return res;
    }
};