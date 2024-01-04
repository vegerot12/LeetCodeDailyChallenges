class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        int res = 0;

        for(auto n: nums){
            freq[n]++;
        }

        for(auto f:freq){
           
                if(f.second ==1 ){
                    return -1;
                }
                else 
                res+= ceil((double)(f.second)/3);
            

        }
        return res;
    }
};