class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int n=nums.size();
        if(n<3) return 0;
       sort(nums.begin() , nums.end());
       
        int res = nums[0] + nums[1] + nums[2];

       for(int i =0;i<n;i++){
           if(i>0 && nums[i] == nums[i-1]) continue;
           int l = i+1, r = nums.size()-1;

           while(l<r){
               int s = nums[i] + nums[r] + nums[l];
               if(abs(s - target) < abs(res - target)){
    res = s;
}
               if(s == target) {
                   return s;
               }
               else if(s > target){
                   r--;
               }
               else{
                   l++;
               }

           }
       }
       return res; 
    }
};