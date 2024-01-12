class Solution {
public:
    bool isVowel(char a){
        a =tolower(a);
        return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        int c=0;
        for(int i =0;i<n;i++){
            if(isVowel(s[i]) )  {
                if(i<n/2) c++;
                else c--;
            }


        }
        return c==0;
    }
};