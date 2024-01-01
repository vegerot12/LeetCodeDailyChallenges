class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), c=s.size();
        int res = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j=0;
        for(int i = 0 ; i < n && j<c;i++ ){
            // start from j
            j = lower_bound( s.begin()+j , s.end(), g[i])- s.begin();
            if(j < c){

            res++;
            j++;
            }
        }
        return res;
    }
};