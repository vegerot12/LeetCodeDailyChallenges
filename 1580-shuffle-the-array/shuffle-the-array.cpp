// all nums less than 1000 so it uses 10 bits out of 32 bits reserved for int
        // so we store x,y together in first n slots 
        // and start filling from end so that we dont overwrite
        // 00000000000x now we left shift x to make space for y using << 10 , left by 10 bits
        // num = num| y so the y will occupy left most bits without disturbing x value
        // 
        // For retreiving 
        // y : y&1 (10 bits) so that y alone will come. 
        // x : >> right shift x to move to original
class Solution {
public:
// O(n) and O(1)
    vector<int> shuffle(vector<int>& nums, int n) {
        

        for(int i =0;i<n;i++){
            nums[i] = nums[i] << 10;
            nums[i] = nums[i] | nums[i+n];

        }

        int j =2*n-1;
          for(int i =n-1;i>=0;i--){
           
            nums[j] = nums[i] & (1023) ; // 10 bits means 2 power 10 = 1024 and 1024-1= 1023 as 1111111111 = 1023 
             nums[j-1] = nums[i] >> 10;
            j-=2;
        }
        return nums;
    }
};