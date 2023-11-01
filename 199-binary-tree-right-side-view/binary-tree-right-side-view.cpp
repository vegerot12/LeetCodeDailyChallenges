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
    void   findRight(TreeNode* root,  vector<int> &res,int level){
        if(!root) return ;

        if(level == res.size()) res.push_back(root->val);
         findRight(root->right, res,level+1);
         findRight(root->left, res,level+1);


    }
    vector<int> rightSideView(TreeNode* root) {
         vector<int> res;
         findRight(root, res,0);
         return res;
    }
};