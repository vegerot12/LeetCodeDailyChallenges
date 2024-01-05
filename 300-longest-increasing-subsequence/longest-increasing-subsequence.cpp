class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> lis;

        lis.push_back(nums[0]);

        for(int i =1; i< nums.size();i++){

            if(lis.back() < nums[i])
            lis.push_back(nums[i]);
            else{
                auto pos = lower_bound(lis.begin(), lis.end(), nums[i])- lis.begin();
                lis[pos] = nums[i];

            }
        }
        return lis.size();
    }
};