class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int n = matrix.size(), m = matrix[0].size();

    //  Iterate over matrix

    for (int row = 1; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            //  Get maximum of all valid path
            int top = matrix[row - 1][col];
            int topLeft =  matrix[row - 1][max(0, col - 1)];
            int topRight = matrix[row - 1][min(m - 1, col + 1)];
            matrix[row][col] = matrix[row][col] + min({top,topLeft , topRight});
        }
    }

    //  Get the max path sum
    int maxPathSum = INT_MAX;
    for (int col = 0; col < m; col++)
    {
       
            maxPathSum = min(maxPathSum, matrix[n - 1][col]);
        
    }
    return maxPathSum;
    }

    int minFallingPathSum1Darr(vector<vector<int>>& matrix) {
         int n = matrix.size(), m = matrix[0].size();

         vector<int> prev(m,INT_MAX);
         prev = matrix[0];

    //  Iterate over matrix
    for (int row = 1; row < n; row++)
    {
    vector<int> dp(m,INT_MAX);


        for (int col = 0; col < m; col++)
        {
            //  Get maximum of all valid path
            int top = prev[col];
            int topLeft =  prev[max(0, col - 1)];
            int topRight =prev[min(m - 1, col + 1)];
            dp[col] = matrix[row][col] + min({top,topLeft , topRight});
        }
        prev = dp;
    }

    //  Get the max path sum
    int maxPathSum = INT_MAX;
    for (int col = 0; col < m; col++)
    {
       
            maxPathSum = min(maxPathSum, prev[col]);
        
    }
    return maxPathSum;
    }
};