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
    int findSum(TreeNode* root, int &res){
        if(!root) return 0;

        int left = findSum(root->left, res);
        int right = findSum(root->right, res);

        int maxChild = max(left, right);
        int maxSingleOrChild = max(root->val, maxChild+root->val);

        int maxTopOrPath = max(maxSingleOrChild, root->val+left+right);
        res = max(res,maxTopOrPath);
        return maxSingleOrChild;

    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;

        int res = INT_MIN;
        findSum(root,res);
        return res;
    }
};