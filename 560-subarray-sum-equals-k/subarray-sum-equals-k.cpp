class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        int sum = 0;
        int res =0;

        m[0] = 1;

        for(int i =0;i<n;i++){
          sum += nums[i];
            if(m[sum - k]){
                res += m[sum-k];
            }
            m[sum] ++;
        }

        return res;
    }
};