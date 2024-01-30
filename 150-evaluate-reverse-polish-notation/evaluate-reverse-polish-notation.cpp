class Solution {
public:
    bool isOperator(string s ){

        if(s.size() > 1 ) return false;
        return s[0] == '*' || s[0] =='/' || s[0] =='+' ||s[0] == '-';

    }

    long eval( long long int a, long long int b, char op){
        switch(op){
            case '+':
            return a + b;

            case '-':
            return a - b;

            case '*':
            return a*b;

            default :
            return a/b;
        }
        
    }
    int evalRPN(vector<string>& tokens) {
        int t =0, i=0; 
        long res = 0;

        while(i<tokens.size()){
            if(!isOperator(tokens[i])){ // number
                tokens[t++] = tokens[i];
            }
            else{
                // evaluate
                long long int b = stoll(tokens[--t]);
                long long int a = stoll(tokens[--t]);

                res = eval(a,b, tokens[i][0]);

                tokens[t++] = to_string(res);


            }
            i++;
        }

        return stoi(tokens[0]);

    }
};