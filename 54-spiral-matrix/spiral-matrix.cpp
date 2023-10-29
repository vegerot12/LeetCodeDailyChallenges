class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> res;

         int rs=0, re = matrix.size()-1, cs =0,ce = matrix[0].size()-1;

         while (rs <= re and cs<=ce){

             int j = cs;
             while(rs <= re and j<=ce ){
                 res.push_back(matrix[rs][j++]);
             }
             rs++;

             int i = rs;
             while(cs <= ce and i<=re ){
                 res.push_back(matrix[i++][ce]);
             }
             ce--;

              j = ce;
             while(rs <= re and j >= cs ){
                 res.push_back(matrix[re][j--]);
             }
             re--;

             i = re;
             while(cs <= ce and i >= rs ){
                 res.push_back(matrix[i--][cs]);
             }
             cs++;
         }
         return res;
    }
};