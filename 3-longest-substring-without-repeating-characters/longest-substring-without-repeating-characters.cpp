class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <=1) return s.size()  ;
        int start=1;
        unordered_map<int,int> m;
        int len = 1,i=0;

        for( i=0;i<s.size();i++){

            
            if(m[s[i]] >= start){
                len = max(len, i-start+1);
              
                start = m[s[i]]+1;
               
            }
            m[s[i]] = i+1;

        }
        return max(len, i-start+1);
    }
};