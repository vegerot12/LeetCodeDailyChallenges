class Solution {
public:
    int expandFromCenter(string& s,int l,int r){
        while(l>=0 and r<s.size() and s[l] == s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int st = 0, len = 0, n = s.size();

        for(int i=0;i<n;i++ ){
            int odd = expandFromCenter(s,i,i);
            int even = expandFromCenter(s,i,i+1);

            int cur = max(odd, even);
            //  cout<<cur;
            if(cur > len){
             st = i -(cur-1)/2;
             len = cur;
            }


        }
        return s.substr(st, len);
    }
};