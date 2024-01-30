class Solution {
public:
    int rec(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        if( i >= matrix.size() || j >= matrix[0].size()|| j< 0) return 1e9;

        if(i == matrix.size()-1) return matrix[i][j];

        if(dp[i][j] != 1e9) return dp[i][j];

        long a =  rec(matrix, i+1,j-1, dp);
        long b =  rec(matrix, i+1,j, dp);
        long c =  rec(matrix, i+1,j+1, dp);

        long cur = min({ a, b, c}) + matrix[i][j];

        return dp[i][j] = cur;


       
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int res = INT_MAX;
        vector<vector<int>> dp( matrix.size()+1,   vector<int>( matrix[0].size()+1 , 1e9));

        for(int i =0;i< matrix[0].size();i++){
            res = min(rec(matrix,0, i , dp) , res);
        }

        return res;
    }
};


// int solve(int i,int j,int n,int m,vector<vector<int>>&dp,vector<vector<int>>matrix){
//         if(j<0||j>=m) return 1e9;
//         if(i==n-1) return matrix[i][j];
//         if(dp[i][j]!=1e9) return dp[i][j];
//         long long take=matrix[i][j];
//         long long a=solve(i+1,j,n,m,dp,matrix);
//         long long b=solve(i+1,j-1,n,m,dp,matrix);
//         long long c=solve(i+1,j+1,n,m,dp,matrix);
//         long long mini=min({a,b,c});
//         take+=mini;
//         return dp[i][j]=take;
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         // vector<vector<int>>dp(n+1,vector<int>(m+1,1e9));
//         // int ans=INT_MAX;
//         // for(int k=0;k<m;k++){
//         //     ans=min(ans,solve(0,k,n,m,dp,matrix));
//         // }
//         // return ans;