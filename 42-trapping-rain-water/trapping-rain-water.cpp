class Solution {
public:
    int trap(vector<int>& h) {
        // stack<int> s;
        // int n = height.size(), i=0,res=0;

        // while(i<n){

        //     while(!s.empty() && height[s.top()] < height[i]){
        //         int top = s.top();
        //         s.pop();
                
        //         int w =  s.empty() ? i :  i - s.top()-1;
        //         int h =    s.empty() ? 0: min(height[s.top()], height[i]) - height[top];
        //         cout<<"popped is"<<height[top]<<"top is "<<(s.empty() ? 0: height[s.top()])<<"cur is"<<height[i]<<" "<<w<<" "<<h<<" "<<w*h<<endl;
        //         res+= w* h;
        //         cout<<"res"<<res<<endl;
                

        //     }
        //    s.push(i);
        //    i++;
        // }
        // return res;

        int res = 0;
        int n = h.size();

        if(n<=2) return 0;

        int l =0, lm = h[0], r = n-1,rm = h[n-1];

        while(l<=r){
            if(lm < rm){
                if(lm <= h[l]){
                    lm = h[l++];
                }
                else res+= lm-h[l++];
            }
            else{
                if(rm <= h[r]){
                    rm = h[r--];
                }
                else res+= rm - h[r--];
            }
        }

        return res;
    }
};