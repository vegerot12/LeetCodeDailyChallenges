class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        sort(it.begin(), it.end());
        int cur = 0;

        for(int i =1;i<it.size();i++){
            if(max(it[i][0] , it[cur][0]) <= min(it[i][1], it[cur][1])){
                it[cur][0]= min(it[i][0] , it[cur][0]);
                it[cur][1]= max(it[i][1] , it[cur][1]);

            }
            else{
                it[++cur] = it[i];
            }
        }

        it.erase(it.begin() + cur+1, it.end());
        return it;
    }
};