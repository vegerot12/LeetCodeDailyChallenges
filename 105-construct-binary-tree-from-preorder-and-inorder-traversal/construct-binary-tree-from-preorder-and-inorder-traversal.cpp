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

    TreeNode* buildTree(int& ind, int& pre, vector<int>& inorder, vector<int>& preorder, int& rightFirst){
        

        if(pre == preorder.size()) return NULL;
        
        if(inorder[ind] == rightFirst){
            ind++;
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pre++]);

        root -> left = buildTree(ind, pre, inorder,preorder, root->val);
         root -> right = buildTree(ind, pre, inorder,preorder,  rightFirst);

return root;
        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rightFirst = INT_MAX;
        int ind=0,pre=0;
        TreeNode* root = buildTree(ind,pre, inorder, preorder,rightFirst);

        return root;

        

        
    }
};