class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        

        unordered_map<int,int> freq;

        int maxFreq = 0;

        for(auto n: nums){
            freq[n]++;
            maxFreq = max(maxFreq, freq[n]);
        }

        vector<vector<int>> res(maxFreq);

        for(auto f: freq){
            int i =0;
            
            for(int t = 0; t < f.second; t++){
                res[i++].push_back(f.first);
            }
        }

        return res;

    }
};