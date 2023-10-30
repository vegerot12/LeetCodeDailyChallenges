class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> res;

        for(int c=0;c<m;c++){
            vector<int> tmp;
            for(int r=0;r<n;r++){
                tmp.insert(tmp.begin(),matrix[r][c] );
                // tmp.push_back(matrix[r][c]);
            }
            res.push_back(tmp);
        }

        // for(int i =0;i<n;i++){
        //     for(int j =0;j<i;j++){
        //         swap(matrix[i][j], matrix[j][i]);
        //     }
        // }

        //  for(int i =0;i<n;i++){
        //    reverse(matrix[i].begin(),matrix[i].end() );
        // }
        matrix = res;
    }
};