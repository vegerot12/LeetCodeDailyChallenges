class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minVal = nums[0], maxVal = nums[0], msf = nums[0], minsf = nums[0];

        int res = nums[0];

        for(int i=1;i<nums.size();i++){
            minVal = minsf;
            maxVal = msf;

            minsf = min({ nums[i], minVal*nums[i] , maxVal *nums[i]});
            msf = max({ nums[i], minVal*nums[i] , maxVal *nums[i]});

            res = max(res,max(msf,minsf));

        }

        return res;
    }
};