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
    private:
    int res = 0;
   
    int diameter(TreeNode* root) {
        if(!root) return 0;
        int l = diameter(root->left);
        int r = diameter(root->right);
        res = max(res, l+r);
        return max(l,r)+1 ;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
               if(!root) return 0;
diameter(root);
        return res;
    }
};