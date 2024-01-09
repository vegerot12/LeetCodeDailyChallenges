/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool checkRes(TreeNode* root,vector<int>& res, int &ind){
    if(!root) return true;

    if(!root->left and !root->right) {
    
    if( ind==res.size() ||  res[ind++] != root->val) return false;

    }

    return checkRes(root->left, res, ind) && 
    checkRes(root->right, res, ind);

}
void buildRes(TreeNode* root,vector<int>& res){
    if(!root) return;

    if(!root->left and !root->right) res.push_back(root->val);

    buildRes(root->left, res);
    buildRes(root->right, res);

}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        int ind = 0;

        buildRes(root1, res);
       return  checkRes(root2, res,ind ) && res.size() == ind;
    }
};