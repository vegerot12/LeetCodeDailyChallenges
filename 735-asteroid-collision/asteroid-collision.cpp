class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
         vector<int> res;
         stack<int> s;

         for(int i =0;i<n;i++){
             if(a[i] > 0 or s.empty()){
                 s.push(a[i]);
                 continue;
             }

             while(!s.empty() and   s.top()>0  and s.top() <abs( a[i])){
                 s.pop();
             }

             
// neg on neg
             if(s.empty() or s.top()<0) s.push(a[i]);
             else if (s.top() == abs(a[i])) s.pop();


         }
         res.resize(s.size());
        int i = s.size()-1;
         while(!s.empty() ){
             res[i--] = (s.top());
             s.pop();
         }
         return res;
    }
};