class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s;

        int n = h.size();
        int res =0;

        for(int i =0;i<=n ;i++){
            int ch = i == n ? 0 : h[i];
            while(!s.empty() && h[s.top()] > ch){
                int t = s.top();
                s.pop();
                int width  =  s.empty() ? i : i- s.top()-1;
                int area = width * h[t];
                res = max(res,area);
                
            }
            s.push(i);
        }
        return res;

        
    }
};