class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        if(n <=1) return nums;

        sort(nums.begin(), nums.end());


    //    vector<vector<int>> res;
    //     res.push_back(nums[0]);

    //     for(int i =1;i<n;i++){
    //         if(max(res.back()[0] , nums[i][0]) <= min(res.back()[1] , nums[i][1]) ){
    //             res.back()[0] = min(res.back()[0] , nums[i][0]);
    //              res.back()[1] = max(res.back()[1] , nums[i][1]);

    //         }else 
    //         res.push_back(nums[i]);
    //     }
    //     return res;

   
    int cur   =0;
    for(int i =1;i<n;i++){
        if(max(nums[cur][0], nums[i][0]) <= min(nums[cur][1], nums[i][1])){
           nums[cur][0] = min(nums[cur][0], nums[i][0]);
           nums[cur][1] = max(nums[cur][1], nums[i][1]);
            
        }
        else           
        nums[++cur]=nums[i];
    }
     nums.erase(nums.begin()+cur+1, nums.end());
     return nums;
    }
};