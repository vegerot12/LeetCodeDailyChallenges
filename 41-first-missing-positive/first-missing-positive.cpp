class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool foundOne=false;

        for(int i = 0;i<n ;i++){
            if(nums[i]==1) foundOne=true;
            if(nums[i] <= 0 || nums[i]>n){
                nums[i] =1;
            }
             
           
        }

        for(int i=0;i<n;i++){
           if(nums[abs(nums[i])-1]>0)
            nums[abs(nums[i])-1] *= -1;
        }
       if(!foundOne) return 1;

        for(int i =0;i<n;i++){
            if(nums[i] >0) return i+1;
        }
        return n+1;
    }
};