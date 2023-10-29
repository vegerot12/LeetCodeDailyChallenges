class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;

        int maxF = 0, res = 0, l=0, n=s.size();

        for(int r = 0;r<n;r++){
            m[s[r]]++;
            maxF = max(maxF, m[s[r]]);

            while(r-l+1 - maxF > k){
                m[s[l]]--;
                l++;
            }

            res = max(res, r-l+1);
        }
        return res;
    }
};