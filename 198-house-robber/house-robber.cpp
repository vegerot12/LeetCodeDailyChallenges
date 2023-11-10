class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if (n==2 ) return max(nums[0], nums[1]);
        int first = nums[0];
        int sec = max(nums[0], nums[1]);
        int cur ;

        for(int i =2;i<n;i++){
            cur = max(sec, first + nums[i]);
            first = sec;
            sec = cur;

        }

        return cur; 

    }
};