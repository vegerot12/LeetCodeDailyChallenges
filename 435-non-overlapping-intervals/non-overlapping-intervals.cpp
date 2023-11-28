class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](auto a, auto b){
            return a[1] < b[1];
        });

        int res =0, n = nums.size();
        int index = 0;
        for(int i =1;i<n;i++){

            if(max(nums[i][0], nums[index][0]) < min(nums[i][1], nums[index][1])){ // overlap
                res++; // inc the cnt to be removed 

            }
            else index=i; 
        }

        return res;
        
    }
};