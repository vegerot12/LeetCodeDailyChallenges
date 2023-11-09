class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msf = nums[0], meh = nums[0];
        int n = nums.size();
        for(int i = 1;i<n;i++){
            meh = max(nums[i], meh +nums[i]);
            msf = max(msf, meh);

        }  
        return msf;
    }
};