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
    void findSum(TreeNode* root, int& targetSum,  unordered_map<long, int> &f, long& curSum, int& cnt){

        if(!root) return ;

        curSum+= root->val;
        cnt += f[curSum - targetSum] ;
        f[curSum]++;

        findSum(root->left, targetSum, f, curSum, cnt);
        findSum(root->right, targetSum, f, curSum, cnt);

        f[curSum]--;
        curSum -= root->val;
        

    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> f;
        f[0] =1;
        long  curSum = 0;
        int cnt = 0;
        findSum(root, targetSum, f, curSum, cnt);
        return cnt;
    }
};