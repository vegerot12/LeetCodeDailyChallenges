class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left =0, right =nums.size()-1,n= nums.size();

        while(left<= right){
            int m = left+(right-left)/2;
            if(nums[m] == target || nums[left] == target || nums[right] == target ){
                return true; 
            }
// move until values at left == m and m == rright
            if(
                left < n and right>=0 and nums[left] == nums[m] && nums[m] == nums[right]
            ){
 while(left < n and right>=0 and nums[left] == nums[m] && nums[m] == nums[right]){
                right--;
                left++;
            }
           
            }
           
           
            
            else if(nums[left] <= nums[m]){ //left not rotated
            if(nums[left] <= target && target < nums[m]){
                right = m-1;
            }else{
                left = m+1;
            }

            }
            else{
                // right not rotated
                if(nums[m]< target && target <= nums[right]) left = m+1;
                else right = m-1;

            }
        }
        return false;
    }
};