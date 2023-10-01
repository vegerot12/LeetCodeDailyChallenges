class Solution {
public:
    string reverseWords(string s) {
        int i =0, n= s.size();

        int space = -1;

        while(i<=n){
            if(i==n || s[i]==' '){
                int start = space+1, end = i-1;
                while(start<end){
                    swap(s[start++], s[end--]);
                }
                space = i;

            }
            i++;
        }
        return s;
    }
};