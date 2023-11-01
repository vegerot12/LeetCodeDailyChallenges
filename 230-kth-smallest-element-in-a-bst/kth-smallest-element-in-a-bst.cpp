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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        
        
        stack<TreeNode*> s;
        while(root){
            s.push(root);
            root = root->left;
        }

        while(!s.empty()){
            TreeNode* tp = s.top();
            s.pop();

            k--;
            if(k==0) return tp->val;

            tp = tp -> right;
            while(tp){
                s.push(tp);
                tp = tp->left;
            }
        }
        return 0;
    }
};