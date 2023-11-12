class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // bucket osrt

        unordered_map<int, int> m;
        int maxF= 0;
        for(auto& n:nums){
            m[n]++;
            maxF = max(maxF, m[n]);
        }

         vector <vector<int>> bucket(maxF +1);

         for(auto& it: m){
             bucket[it.second].push_back(it.first);
         }

         vector<int> res;

         while(true){
             for(auto& e: bucket[maxF]){
                 res.push_back(e);
                 k--;
                 if(k==0) return res;
             }
             maxF--;
         }


return res;

    }
};