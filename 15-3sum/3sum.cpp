class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         int n = nums.size();
         if(n<3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
       
        
        for(int i =0;i<n;i++){
        if ((i>0) && (nums[i]==nums[i-1]))             continue;
// to avoid repeated ele 

            int l = i+1, r = n-1; 
            while(l<r){
                int s = nums[i]+nums[l]+nums[r];
                if(s==0) {
                    res.push_back({ nums[i], nums[l], nums[r]});
                    while(l < r and nums[l] == nums[l+1]){
                        l++;
                    }
                     while(  r>l  and nums[r] == nums[r-1]){
                        r--;
                    }
                    l++;
                    r--;
                }
                else if (s<0) l++;
                else r--;
            }
        }
        return res;
    }
};