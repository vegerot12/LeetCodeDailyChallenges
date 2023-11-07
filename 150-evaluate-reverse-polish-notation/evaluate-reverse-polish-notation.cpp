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
    int evalRPN(vector<string>& t) {
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
};