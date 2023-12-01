class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
       if(nums.size()==2) return max(nums[0], nums[1]);
        if( nums.size() <3) return max( (nums[0]+nums[2]) , nums[1]) ;
        int f1 =0, s1 =0, f2=0, s2=0, r1=0,r2=0;
        f1 = nums[0], s1 = max(nums[0], nums[1]), s2 = max(nums[1], nums[2]), f2 = nums[1];
        r1 = max(f1,s1); 
        r2 = max(f2,s2);
        for(int i=2;i<nums.size();i++){
            if(i!= nums.size()-1 ){
            r1 = max(f1 +   nums[i] , s1);
            f1 = s1;
            s1 = r1;
            }
            if(i!=2 ){
            r2 = max(f2 + nums[i] , s2);

            f2 = s2;
            s2 = r2;
            }
           
        }
        return max(r1,r2);
    }
};