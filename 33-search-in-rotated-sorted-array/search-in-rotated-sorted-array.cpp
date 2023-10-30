class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while(l<=r){

            int m = (r-l)/2 + l;
            if(nums[m] == target ) return m;
            if(nums[l] == target) return l;
            if(nums[r] == target) return r;
            
            if(nums[0] < nums[m]){ // left straigjt
                if(nums[0] <= target and target < nums[m]){
                    r=m-1;
                }
                else l = m+1;
            }
            else{ // righjt striaght
             
                 if(nums[m] < target and target <= nums[r]){                 
                    l = m+1;
                }
                else r=m-1;
            }
        }
        return -1;
    }
};