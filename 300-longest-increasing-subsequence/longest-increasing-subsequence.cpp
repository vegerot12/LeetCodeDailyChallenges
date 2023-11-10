class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        lis.push_back(nums[0]);

        for(int i =1;i<nums.size();i++){
            if(lis.back() < nums[i]){
                lis.push_back(nums[i]);
                cout<<"pushing"<<nums[i]<<endl;
            }
            else{
                auto posOfFirstSmaller = lower_bound(lis.begin(), lis.end(),nums[i]) - lis.begin();
                
                    lis[posOfFirstSmaller] = nums[i];
                cout<<"replacing"<<nums[i]<<endl;


                
            }
        }
        return lis.size();
    }
    
};

