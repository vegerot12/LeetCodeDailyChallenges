class Solution {
public:
// O(n) and O(1) // dont go for subarray multiplicaltion n*(n+1)/2 it causes int overflow
    long long zeroFilledSubarray(vector<int>& nums) {
       long long res =0;
       for(int end = 0, start =0; end<nums.size();end++){
           if(nums[end]!=0)
           start = end+1; // start new window
           res+= end - start +1;  // this can happen for all cases if end points to a zero then end-start+1 is a valid window i
           // if end points to non zero then start = end+1 . now end - (end+1) +1 = -1+1 =0 
       }

        return res;
    }
};