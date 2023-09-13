class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> dp(n,1);
        int cnt =0;
        bool slope = false;

        
        // increasing slope
        for(int i =1;i<n;i++){
            if(r[i] > r[i-1]){
            dp[i] = dp[i-1] + 1;
            }
           
            if(i==n)  slope = true; 
        }
        // decreasing slope from right to left 
        for(int i =n-1;i>=1;i--){
            if(r[i] < r[i-1]){
                dp[i-1] = max(dp[i-1], dp[i]+1); // if what is currently present in i-1 is alrd greater than i then leave as it is , if not change it to val at i +1 so that it has more than i  


            }
            cnt+= dp[i];
        }
        return cnt+dp[0]; // loop ends at 1 itself so simply at dp[0] to res 


    }
};