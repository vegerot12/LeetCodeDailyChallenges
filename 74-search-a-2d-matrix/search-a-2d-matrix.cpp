class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l =0,n=matrix.size(), c = matrix[0].size() ,r = c*n-1;
        while(l<=r){
            int m = (r-l)/2 + l;
            if(matrix[m/c][m%c] == target) return true;
            
            if(matrix[m/c][m%c] > target) r = m-1;
            else l = m+1;
        }
        return false;
    }
};