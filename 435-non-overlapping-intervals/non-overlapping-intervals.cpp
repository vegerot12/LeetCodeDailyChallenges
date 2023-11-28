class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort(nums.begin(), nums.end(), [](auto a, auto b){
        //     return a[1] < b[1];
        // });

        // int res =0, n = nums.size();
        // int index = 0;
        // for(int i =1;i<n;i++){

        //     if(max(nums[i][0], nums[index][0]) < min(nums[i][1], nums[index][1])){ // overlap
        //         res++; // inc the cnt to be removed 

        //     }
        //     else index=i; 
        // }

        // return res;
        int n = intervals.size();
        if(n==1) return 0;
         sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        int ans = 0;

        for(int i = 0; i < n-1; i++){
            if(intervals[i+1][0] < intervals[i][1]){
                ans++;
                intervals[i+1][1] = min(intervals[i][1], intervals[i+1][1]);
            }
        }
        return ans;
    }
};