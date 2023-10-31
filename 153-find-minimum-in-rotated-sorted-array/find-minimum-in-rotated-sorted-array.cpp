class Solution {
public:
    int findMin(vector<int>& nums) {
         int l = 0, r = nums.size()-1;
if(nums.size()==1) return nums[0];
        while(l<r){

            int m = (r-l)/2 + l;
               
            if(nums[0] < nums[r]) return nums[0];
            
            if(m-1 >= 0 and nums[m] < nums[m-1]) return nums[m];
            if(m+1 < nums.size() and nums[m] > nums[m+1]) return nums[m+1];
            
            if(nums[0] < nums[m]) l = m+1;
            else r = m-1;
        }
        return 0;
        
    }
};