class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int cnt = 0, res=0;

        int i = 0, n = nums.size();
        while(i<n){
            if(s.count(nums[i]-1)==0 ){
              
               while(s.find(nums[i]+cnt) != s.end()){
                 cnt++;
                 
               }
                res = max(res,cnt);

            }
            i++;
            cnt =0 ;

        }
        return res;

    }
};