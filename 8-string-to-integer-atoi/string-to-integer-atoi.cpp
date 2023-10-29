class Solution {
public:
    int myAtoi(string s) {
        long int sign = 1, res = 0;
        int n = s.size(), i = 0;
        
        while(i<n){
            while(s[i] == ' '){
                i++;
               continue;
            }
            
            if(s[i] == '-'){
                sign = -1;
                i++;
            }
            else if(s[i] == '+'){
                i++;
            }
           

           while(i<n and s[i]>='0' and s[i]<='9') {
                res = res * 10 + (s[i++]-'0') ;
                if(res * sign >= INT_MAX) return INT_MAX;
                if(res * sign <= INT_MIN) return INT_MIN;
                
            }

            return res*sign;
            
        }
        return res*sign;
    }
};