class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& t, vector<int>& target) {
        vector<int> res(3);
    
    for(int i = 0;i<t.size();i++){
        if(t[i][0] <= target[0] and t[i][1] <= target[1] and t[i][2] <= target[2]){
            res[0] = max(t[i][0], res[0]);
            res[1] = max(t[i][1], res[1]);
            res[2] = max(t[i][2], res[2]);

        }

    }
    return res == target;
        
    }
};