class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
         vector<vector<string>> res;

         for(auto &s: strs){
            string org = s;
              sort(s.begin(), s.end());
             m[s].push_back(org);

         }

         for(auto it:m){
             res.push_back(it.second);
         }

         return res;
    }
};