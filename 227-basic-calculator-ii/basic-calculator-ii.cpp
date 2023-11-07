class Solution {
public:
    int calculate(string s) {
        int cur=0, sum =0, n = s.size();
        char op = '+';

        for(int i = s.find_first_not_of(' ',0) ; i<n and i>=0 ; i = s.find_first_not_of(' ',i)){

            if(isdigit(s[i])){
                int tmp = s[i++]-'0';
                while(i<n and  isdigit(s[i])){
                    tmp = tmp*10 + (s[i]-'0');
                    i++;
                }
                if(op == '+') cur+= tmp;
                else if (op == '-') cur -= tmp;
                else if ( op == '*' ) cur *= tmp;
                else if(op=='/') cur/=tmp;
            }

            else {
                if(s[i] == '+' || s[i]=='-'){
                    sum += cur;
                    cur = 0;

                } 
                op = s[i];
                i++;
            }
        }
        return cur + sum;
       
    }
};