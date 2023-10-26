class Solution {
public:
    
    // 1. store the running prod in prod vector such that prod[0] = 1 abd prod of
    // i is prod of all ele from 0 to i-1
    
    // 2. from right to left
    // start at last but one index
    // have a tmp = 1 -- this tmp is going to store the runniong prod of right to left 
    // at any instance of i<n-1, tmp will storet eh prod of all ele from i+2 to n-1
    // so we can say res[i] = prod[i] * nums[i+1] * tmp;
     //                      0 to i-1   * next * i+2 to n-1
    // there by we get prod of all ele except self for every i
    
    // Note : we can reuse the prod to stoer the final res as well
    // prodRight is tmp 
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prod(n);

        prod[0] = 1;
      
      // LTR
      for(int i =1;i<n;i++){
          prod[i] = prod[i-1]* nums[i-1];

      }
// RTL
      int right=1;
       for(int i=n-2;i>=0;i--){
          right = nums[i+1]* right;
          prod[i] = prod[i]*right;

      }
        
           
       
        return prod;
    }
     
};