// approach 1
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//           int arr[m][n];

//         for(int i=0;i<m;i++){
//             arr[i][0] = 1;  // first col is 1 - since we can only move bottom or right there is only one way to reach this 
//         }
//         for(int j=0;j<n;j++){
//             arr[0][j]=1; // first row 1 - since we can only move bottom or right there is only one way to reach this
//         }
//         for(int i=1;i<m;i++){
//             for(int j=1;j<n;j++){  
//                 arr[i][j] = arr[i-1][j] +arr[i][j-1];    // dist upto arr[i][j] is dist upto top and left , since we need no of ways we can add both top and left
//             }
            
//         }
//         return arr[m-1][n-1];
//     }
// };

// approach 2 
/*
- instead of 2d array we can do it in 1D array itself because the prev row val is same as cur row val before it is updated 

*/
class Solution {
public:
    int uniquePaths(int m, int n) {
         vector<int> dp(n,1); // first row is 1 because only one way to reach all cols in first row and all rows in first col 
         for(int i =1;i<m;i++){
             for(int j = 1;j<n;j++){
                 dp[j] = dp[j] + dp[j-1];
              }
         }
        // here dp[j] refers to prev row and dp[j-1] refers to prev col
            
         
    return dp[n-1];
    }
};
