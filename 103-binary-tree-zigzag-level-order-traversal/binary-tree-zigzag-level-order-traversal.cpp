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
        deque<TreeNode*> q;
        vector<vector<int>> res;
        q.push_back(root);

        bool RTL = true;

        while(!q.empty()){
            int s = q.size();
            vector<int> cur;

            while(s--){
   
              

                if(RTL){
                    auto p = q.front();
                    q.pop_front();

                    cur.push_back(p->val);
                    if(p->left)
                    q.push_back(p->left);
                    if(p->right)
                    q.push_back(p->right);

                }
                else{
                    auto p = q.back();
                    q.pop_back();

                    cur.push_back(p->val);
                    
                    if(p->right)
                    q.push_front(p->right);
                    if(p->left)
                    q.push_front(p->left);

                }

            }
            res.push_back(cur);
            RTL = !RTL;
        }

        return res;
    }
};