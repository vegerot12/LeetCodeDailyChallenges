class Solution {
public:
    // int minOperations(vector<int>& nums, int x) {
    //     // if sum is sum of all ele, we need to remove x so remainng sum-x . we need to find len og longest subarray with sum = sum-x . total len - that len = ans
    //     int sum=0,len =0;
    //     for(int &n:nums) sum+= n;
    //     int rem = sum-x;

    //     // find rem 

    //     int cur = 0;
    //     int start=0;
    //     for(int end =0;end<nums.size();end++){
    //         cur+= nums[end];

    //         while(start<nums.size() && cur>rem )
    //         cur-= nums[start++]; // remove from begining of window

    //         if(cur == rem) len = max(len, end-start+1 );

    //     }
    //     if(len==0) return -1;
    //     return nums.size() - len;
    // }
    int minOperations(vector<int>& v, int x) 
    {
        int i,len=0,sum1=0,sum2=0;
        for(i=0;i<v.size();i++)
            sum2+=v[i];                  // calculating sum of whole array 
			
        sum2-=x;   //  this is sum of remiaing elements . after removing X 
		
        if(sum2==0)        // sum of array is equal to X . means we'll have to remove all elements
            return v.size();
			
// sliding window technique 
// i points to begining of subarray and j points to end of subarray 

		// sum2 is desired sum while sum1 is current sum
        int j;i=0;
        for(j=0;j<v.size();j++)
        {
            sum1+=v[j];
			
            while(i<v.size()&&sum1>sum2) // if sum of current subaaray is greater than desired sum
                sum1-=v[i++];
				
            if(sum1==sum2)  // if sum of current subarray is equal to desired sum then update length
                len=max(len,j-i+1); // we want subarray  with maximum length 
        }
        if(!len)        // No subarray found with desired sum .
            return -1;
        return v.size()-len;
    }
};