class Solution {
public:
    int findMin(vector<int>& nums) {
         int l = 0, r = nums.size()-1;
if(nums.size()==1) return nums[0];
        while(l<r){

            int m = (r-l)/2 + l;
            //    if(nums[m]> nums[m+1]) return nums[m+1]; // if there are only 2 ele , m=l so m-1 will not exisit but m+1 wull exist so try m, m+1 before m,m-1
            // if(nums[m] < nums[m-1]  ) return nums[m];
            // if(nums[0] < nums[r]) return nums[0];
            
            // if(nums[m] > nums[m+1]){ 
            //     return nums[m+1];
            // }
            
            // if(nums[0] < nums[m]) l = m+1;
            // else r = m-1;
             if(nums[r] > nums[0]) return nums[0] ; // interval is sorted , unrotated so return first ele

            if(nums[m]> nums[m+1]) return nums[m+1]; // if there are only 2 ele , m=l so m-1 will not exisit but m+1 wull exist so try m, m+1 before m,m-1
            if(nums[m] < nums[m-1]  ) return nums[m];

            if(nums[0] < nums[m]) {// left un rotated so right is rotated and has the smallest
               l = m+1;
            }
            else // left is rotated 
            r = m-1;
        }
        return 0;
    }
};