class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = nums[n-1];
        int target  = n-1;

       for(int i = n-2;i>=0;i--){
           if(nums[i] + i >= target){
               target   = i;
           }
          
       }
       return target  == 0;
    }
};