class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int n = height.size(), i=0,res=0;

        while(i<n){

            while(!s.empty() && height[s.top()] < height[i]){
                int top = s.top();
                s.pop();
                
                int w =  s.empty() ? i :  i - s.top()-1;
                int h =    s.empty() ? 0: min(height[s.top()], height[i]) - height[top];
                res+= w* h;
                

            }
           s.push(i);
           i++;
        }
        return res;
    }
};