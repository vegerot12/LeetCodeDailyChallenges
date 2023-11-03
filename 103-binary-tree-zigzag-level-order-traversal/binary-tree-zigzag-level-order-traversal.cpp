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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);

        bool LTR = true;

        while(!q.empty()){
            int s = q.size();
            vector<int> cur(s);
            int i =0;

            while(i<s){
                auto p = q.front();
                    q.pop();
               int ind = LTR ? i : s-i-1;
               cur[ind] = p->val;

               if(p->left)
               q.push(p->left);
               if(p->right)
               q.push(p->right);
               i++;
                    

               

            }
            res.push_back(cur);
            LTR = !LTR;
        }

        return res;
    }
};