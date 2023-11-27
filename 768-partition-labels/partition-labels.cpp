class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for(int i =0;i<s.size();i++){
            m[s[i]] = i;
        }
         vector<int> res;
        int maxEnd =0, start=0;
         for(int i =0;i<s.size();i++){
           maxEnd = max( m[s[i]], maxEnd);
           if( i == maxEnd){
                res.push_back(i-start+1);
                start = i+1;
           }
        }
        return res;
    }
};