class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> m;
        int start =0, res =1; // initially 1 string so res starts at 1
        for(int i=0;i<s.size();i++){
            if(m[s[i]]-1>=start)
            {
                res++;
                start = i;
                m[s[i]] = i+1;
                }
            m[s[i]]=i+1;
            
        }
        return res;
    }
};