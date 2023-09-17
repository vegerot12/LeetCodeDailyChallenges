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
void findGood(TreeNode* root, int& cnt, int msf){
        if(!root) return ;
        if(root->val >= msf){
            msf = root->val;
            cnt++;
        }
        findGood(root->left, cnt, msf);
        findGood(root->right, cnt, msf);

    
}
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int cnt = 0, msf = root->val;
        findGood(root, cnt, msf);
        return cnt;
    }
};