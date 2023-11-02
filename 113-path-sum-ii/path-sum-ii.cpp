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
    void findSum(TreeNode* root, vector<int>& cur, vector<vector<int>>& res,int targetSum ){

        if(!root) return ;
            
            
            cur.push_back(root->val);
            
        if(!root->left and !root->right and targetSum==root->val ) {
            res.push_back(cur);
            
        }
        else{

        findSum(root->left, cur,res,targetSum - root->val);
        findSum(root->right, cur,res,targetSum -root->val);
        }
       
        cur.pop_back();




    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> cur;
       
        findSum(root, cur,res, targetSum);
        return res;
    }
};