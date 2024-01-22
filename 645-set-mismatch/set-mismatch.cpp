class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //  solution 1 : hash map O(n) and O(n)
        // find count of all. if count is 0 missing if cnt is 2 duplicate 

        // sol 2: negative for visited. atlast which index remains pos is missing num. 

        vector<int> res(2);
int n = nums.size();
        for(int i =0;i<n;i++){
            // num at index = cur num 
            int cur = abs(nums[i]);
           // if any num is already -ve, we negate  we add itt to duplocate 
           if(nums[cur-1]< 0) res[0] = cur; // dup
            // we visit the index = cur num, so we change the number at prev index , because this cur num say = 1 is supposed to be at 0th index 
           else nums[cur-1] = nums[cur-1] * -1;

            
        }

// now we look for all nums if there is a index thats posititve then that index has not been visited. so if index = 0 then number supposed to be at tat index is index+1 so we take i+1 as the missing number 
        for(int i =0;i<n;i++){
            if(nums[i] > 0 ) {

            res[1] = i+1;
            return res;
            }
        }
return res;
    }
};