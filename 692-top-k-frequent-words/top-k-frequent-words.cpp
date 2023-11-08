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
            cout<<"pushing"<<it.first<<"in"<<it.second<<"bucket"<<endl;
            bucket[it.second].push_back(it.first);
        }
        vector<string> res;
        int f = maxF;
        while(true){
            auto& cur = bucket[f--];
            cout<<cur.size();
            sort(cur.begin(), cur.end());

            int i =0;
            while(i<cur.size()){
                cout<<cur[i];
                res.push_back(cur[i++]);
                if(res.size()==k) return res;
                
            }
        }

return res;


    }
};