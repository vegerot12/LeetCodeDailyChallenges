class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        int n = nums.size();

        lis.push_back(nums[0]);

        for(int i =1 ;i<n;i++){

            if(lis.back() < nums[i]){
                lis.push_back(nums[i]);
            }
            else{
                int posOfNextGrter = lower_bound(lis.begin(), lis.end(), nums[i])-lis.begin();
                lis[posOfNextGrter] = nums[i];
            }


        }
        return lis.size();
    }
};