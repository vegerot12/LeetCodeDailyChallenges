class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& it) {
        sort(it.begin(), it.end(), [](const vector<int> a, const vector<int> b){
            return a[1]==b[1] ? a[0]<b[0]: a[1] < b[1]  ;
        });

        int cur =0,res=0;
        for(int i =1;i<it.size();i++){
            if(max(it[i][0], it[cur][0]) < min(it[i][1], it[cur][1])){
                res++;
            }
            else 
            cur = i;
        }
        return res;
    }
};