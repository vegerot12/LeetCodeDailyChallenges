class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<=1) return n;
        unordered_map<char, int> m;
        int res = 0;
        int start = 0, i=0;
    

        for( i = 0;i<n;i++){
            if(m.find(s[i])!= m.end()  && m[s[i]] >= start){
                res = max(res, i-start);
                start = m[s[i]]+1; // next to this char prev occurence
               
            }
             m[s[i]] = i;
            
        }

        return max(res, i-start); 
    }
};