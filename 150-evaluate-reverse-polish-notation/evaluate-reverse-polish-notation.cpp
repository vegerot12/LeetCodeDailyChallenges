class Solution {
public:
    bool isOp(string c){
        return c=="+"|| c=="-" || c=="/" || c=="*";
    }

    int eval(int a, int b, char c){
        switch(c){
            case '+':
            cout<<a+b;
            return a+b;

            case '-':
            cout<<a-b;
            return a-b;

            case '*':
            cout<<a*b;
            return a*b;

            case '/':
            cout<<a/b;
            return a/b;

        }
        return 0;
    }
    int evalRPNSTACK(vector<string>& t) {
        stack<long> s;

        int i =0, n = t.size();
        for(int i=0;i<n;i++){
            if(isOp(t[i])){
              long b =  s.top();
              s.pop();
              long a = s.top();
              s.pop();
              long res = eval(a,b,t[i][0]);
              cout<<res;
              s.push(res);


            }
            else{
                int num= stoi(t[i]);
                s.push(num);
            }

        }
        return s.top();
    }
    int evalRPN(vector<string>& t) {
        

        int i =0, n = t.size(), top =0;
        long long res;
        for(int i=0;i<n;i++){
            if(isOp(t[i])){
                  long long int b = stoll(t[--top]); // take last two as int
                
                long long int a = stoll(t[--top]);
               
            
             
               res = eval(a,b,t[i][0]);
              cout<<res;
              
              t[top++] = to_string(res);
           


            }
            else{
                t[top++]= (t[i]);
                
            }

        }
        return stoi(t[0]);
    }
};