class Solution {
public:
    // Contiguos subarray so we can do a cumulative sum a
// for each i, sum contains sum of all ele from o to i
    // check if cur sum-k is present in freq_map if so we get as many res as the freq of sum-k in the freq_map. 
    
    // sum - k = x if there exists a subset with sum x in the array then sum - x = k there also exists a subset with sum k in the array thats why we check for sum-k in map. if sum = k then also sum-k = 0  and we know that mp[0]=1

    // so for 12 then 
    int subarraySum(vector<int>& nums, int k) {
      int n = nums.size();
        if(n==1) return k==nums[0]; // if nly one ele and if k is same then 1 . 

        int res = 0;
        int sum_so_far =0;
        unordered_map<int,int> m;
        
        m[0] = 1; // by default the sum 0 is subset is 1, empty subset 
        // we will not consider empty subset because a subarray is a non empty subset
        // m[0]  helps when sum == k and sum-k will look for 0 

        // 1 2 3 4 - k=6
        //m:1 3 6 10 
    // sum-k:-5 -3 0 4    
        for(int i=0;i<n;i++){
            sum_so_far += nums[i];
            res += m[sum_so_far-k];
            // from cur state or cur sum we subtract k and e reach some other state or some other sum , and if such a sum is present as one of the prefix sum then the current subtracted k exists as a subarray in the given array // 
         // if  m[sum_so_far - k] is > 1 means it has contributed to multiple subarray already
            m[sum_so_far]++;
        }
        
        return res;
    }
};