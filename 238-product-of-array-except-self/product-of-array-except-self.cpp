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
      
        prod[0] =1;
        
        // 1. runninf prdduct  of i contains  prod from 0 to i-1
       for(int i =1;i<n;i++)
           prod[i] = prod[i-1] * nums[i-1]; 
        
        int prodRight =1; // prodRight always contains prod form right end to i+1 in reverse order 
       // 2. right to left
       for(int i=n-2;i>=0;i--)
       {
           prodRight *= nums[i+1]; 
           prod[i] *=  prodRight ; // prod[i] contains prod from 0 to i-1 and prodRight contains form i+1 to n so except i all 
     
           
       }
        return prod;
    }
     
};