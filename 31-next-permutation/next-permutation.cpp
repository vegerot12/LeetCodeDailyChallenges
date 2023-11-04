class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int small = -1;
        
        for(int i = n-1; i>0 ;i--){
            if(nums[i-1] < nums[i]){
                small = i-1;
                break;
            }
        }

        int large = -1;

        if(small != -1){
            for(int i = n-1 ; i >= 0; i--){
                if(nums[small] < nums[i]){
                    large = i;
                    swap(nums[small], nums[large] );
                    reverse(nums.begin()+small+1, nums.end());
                    return;
                }
            }
        }
        else
        sort(nums.begin(), nums.end());


    }
};