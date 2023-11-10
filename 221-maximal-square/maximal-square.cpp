class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size(), c= matrix[0].size();
        vector<int> dp(c,0);
//         int copyOfcurJForTopLeft ,res=0,topleft;
// // copyOfcurJForTopLeft stores the j before it is updated so that it can act as i-1,j-1 for next j 
//         for(int i=0;i<r;i++){
//            for(int j=0;j<c;j++){
//                copyOfcurJForTopLeft = dp[j]; // store it here to use for i-1,j-1
//                if(i==0 or j==0 or matrix[i][j] == '0') 
//                dp[j] = matrix[i][j] - '0';
//                else
//                dp[j] = min({dp[j],dp[j-1], topleft}) +1; 
//                res = max(res, dp[j]);
//                topleft=copyOfcurJForTopLeft;
//            }
//         }
        int curJ, topL, res=0;
        for(int i=0;i<r;i++){
            for(int j =0;j<c;j++){
                curJ=dp[j];
                if(i==0 or j==0 or matrix[i][j]=='0')
                dp[j] = matrix[i][j] - '0';
                else{
                    dp[j] = 1+min({dp[j], dp[j-1],topL});
                }
                topL = curJ;
                res = max(res, dp[j]);
            }
        }
        return res*res;
    }
};