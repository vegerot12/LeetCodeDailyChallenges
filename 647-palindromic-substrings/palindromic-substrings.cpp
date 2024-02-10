class Solution {
public:
    int countPal(int st, int e, string s){
       int noOfPal =0;
      
        while(st >=0 && e< s.size() && s[st]==s[e]){
            st--;
            e++;
           noOfPal++;
        }

        return noOfPal;

    }

    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for(int i=0;i<n;i++){
           res+= countPal(i,i,s);
            res += countPal(i,i+1,s);

          

        }
        return res;
    }
};