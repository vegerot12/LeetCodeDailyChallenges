class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <=1) return s.size()  ;
        int start=0; // if we keep start as 1 it will interfere with map 0
        unordered_map<int,int> m;
        int len = 1,i=0;

        for( i=0;i<s.size();i++){

            
            if(m.find(s[i]) != m.end() && m[s[i]] >= start){
                len = max(len, i-start);
              
                start = m[s[i]]+1;
               
            }
            m[s[i]] = i;

        }
        cout<< max(len, i-start);
        return m.size() == s.size() ? max(len, i-start): max(len, i-start);
    }
};