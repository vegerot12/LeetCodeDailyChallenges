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
    int add(TreeNode* root, int low, int high){
        if(!root) return 0;

        if(root->val > high)
        return add(root->left, low, high);
        else if(root->val < low)
       return add(root->right, low, high);
        else
        return root->val +add(root->right, low, high) + add(root->left, low, high) ;

        


        // if(root->val>= low && root->val <= high) sum+= root->val;

        // if(root->val >= low)
        // add(root->left, low, high, sum);
        // if(root->val <= high)
        // add(root->right, low, high, sum);

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
       
        return add(root, low, high);
      
    }
};