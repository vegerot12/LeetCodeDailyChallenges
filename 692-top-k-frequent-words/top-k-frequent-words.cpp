class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        int maxF = 0;

        for(auto w:words){
            m[w]++;
            maxF = max(maxF, m[w]);
        }

        vector<vector<string>> bucket(maxF+1);

        for(auto it: m){
          
            bucket[it.second].push_back(it.first);
        }
        vector<string> res;
        int f = maxF;
        while(true and k>0){
            auto& cur = bucket[f--];
          
            sort(cur.begin(), cur.end());

            int i =0;
            while(i<cur.size() and k>0){
               
                res.push_back(cur[i++]);
               k--;
            }
        }

return res;


    }
};