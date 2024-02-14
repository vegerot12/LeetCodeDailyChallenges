class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       int n = prices.size();
        if(n==1||n==0) return 0;
        
        int m[n][2]; 
        
        m[0][0] = 0;
        m[0][1] = -prices[0]-fee;
        m[1][0] = max(m[0][0], m[0][1]+prices[1]);
        m[1][1] = max(-prices[1]-fee, m[0][0]-prices[0]-fee); // would have bought it on day 0 or day 1
       
        for(int i=2;i<n;i++){
            m[i][0] = max( m[i-1][0] , m[i-1][1]+prices[i]);
            m[i][1] = max( m[i-1][1] , m[i-1][0]-prices[i]-fee);
            
        }
        // always return 0th because u must not have a stock in hand if you calculate profit, you should have no stock 
        return m[n-1][0]; 
       
    }
};