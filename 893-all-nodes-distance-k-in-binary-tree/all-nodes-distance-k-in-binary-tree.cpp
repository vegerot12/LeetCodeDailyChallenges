/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findNodesK(TreeNode* root , int k,vector<int>& res){
        if(!root) return ;
        cout<<"In findNodesK "<<root->val<<endl;
        if(k==0) {
            res.push_back(root->val);
            return;
        }

         findNodesK(root->left, k-1, res);
         findNodesK(root->right, k-1, res);
    }
    int findTarget(TreeNode* root , int k,TreeNode* target, vector<int>& res){

        if(!root) return -1;
                cout<<"In findT "<<root->val<<endl;

        if(root->val == target->val){
            findNodesK(root, k, res);
            // findNodesK(root->right, k-1, res);
            return 0;
        }   
        auto left = findTarget(root->left, k, target,res);

       

        if(left!=-1){
            if(left+1 ==k ) {
                res.push_back(root->val); // k-1
            return -1;
            }
            else
             findNodesK(root->right, k-left-2, res);
             return left+1;
        }
        auto right = findTarget(root->right, k, target,res);

        if(right != -1){
            if(right + 1 == k){
                 res.push_back(root->val); // k-1
            return -1;
            }
            else
             findNodesK(root->left, k-right-2, res);
             return right +1;
        }

        
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;

        findTarget(root, k, target, res);
        return res;
    }
};