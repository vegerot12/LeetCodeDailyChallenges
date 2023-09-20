class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // if sum is sum of all ele, we need to remove x so remainng sum-x . we need to find len og longest subarray with sum = sum-x . total len - that len = ans
        int sum=0,len =0;
        for(int &n:nums) sum+= n;
        int rem = sum-x;

        if(rem == 0 ) return nums.size();

        // find rem 

        int cur = 0;
        int start=0;
        for(int end =0;end<nums.size();end++){
            cur+= nums[end];

            while(start<nums.size() && cur>rem )
            cur-= nums[start++]; // remove from begining of window

            if(cur == rem) len = max(len, end-start+1 );

        }
        if(len==0) return -1;
        return nums.size() - len;
    }
};