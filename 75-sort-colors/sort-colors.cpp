class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, m = 0, h = n-1;

        while(m<=h){
           
            if(nums[m] == 2){ // h is unvisited so it can be anything so dont move m we need to check m again 
                swap(nums[h--], nums[m]);
            }
            else if(nums[m] == 0){ // l is visited it can have only 0 or 1 both are fine so move m
                swap(nums[l++], nums[m++]);
            }
            else m++; // it has 1 so ok move m
        }
    }
};