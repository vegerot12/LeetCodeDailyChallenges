class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();
        if(n==1 ||n== 0) return 0;
        int maxWindowEnd = nums[0];
        int curWindowEnd = nums[0];

        int steps =1,i=0;

        while(i<n){
            maxWindowEnd = max(maxWindowEnd,i+nums[i]);
            // if(i==n-1) return steps;
            if(i==curWindowEnd){ 
                curWindowEnd = maxWindowEnd;
                steps++;
                }
                if(curWindowEnd == n-1) return steps;
            i++;
            
        }
        return steps;}
    //     int n = nums.size();
    //     if(n==0 || n==1) return 1;
        
    //     int cur_window_end = nums[0], max_window_end = nums[0];
    //     int i =0, steps =1;

    //     while(i<n){
    //         if(nums[i]+i > max_window_end) max_window_end = nums[i]+i;
    //         if(i==n-1) return steps;
    //         if(cur_window_end == i){
    //             steps++;
    //             cur_window_end = max_window_end;
    //         }
    //         i++;
    //     }
    //     return steps;
    // }
};

