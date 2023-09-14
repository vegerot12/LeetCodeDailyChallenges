class Solution {
public:
    int partitionString(string s) {
        vector<int> m(26,0);
        int start =0, res =1; // initially 1 string so res starts at 1
        for(int i=0;i<s.size();i++){
            if(m[s[i]-'a']-1>=start)
            {
                res++;
                start = i;
                }
            m[s[i]-'a']=i+1;
            
        }
        return res;
    }
};