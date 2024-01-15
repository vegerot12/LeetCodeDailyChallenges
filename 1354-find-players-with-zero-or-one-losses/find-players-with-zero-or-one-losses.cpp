class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> p;

        for(auto m:matches){
            if(p[m[0]] == 0) p[m[0]]++;

            if(p[m[1]] > 0) p[m[1]] = -1;
            else p[m[1]]--;
        }
     vector<vector<int>> res(2);

     for(auto pt:p){
         if(pt.second > 0) res[0].push_back(pt.first);

         if(pt.second == -1) res[1].push_back(pt.first);
     }
     sort(res[0].begin(), res[0].end());
     sort(res[1].begin(), res[1].end());

     return res;

    }
};