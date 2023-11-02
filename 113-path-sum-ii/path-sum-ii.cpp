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
    void findSum(TreeNode* root, vector<int>& cur, vector<vector<int>>& res,int& targetSum , int curSum){

        if(!root) return ;

        // if(root->val + curSum > targetSum) return;
            
            curSum += root->val;
            cur.push_back(root->val);
            cout<<curSum<< root->val<<endl;
        if(!root->left and !root->right and targetSum==curSum ) {
            res.push_back(cur);
            
        }

     

      
      
        findSum(root->left, cur,res,targetSum,curSum);
        findSum(root->right, cur,res,targetSum,curSum);
        curSum -= root->val;
        cur.pop_back();




    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> cur;
        int curSum = 0;
        findSum(root, cur,res, targetSum,curSum);
        return res;
    }
};