// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//      int widthOfBinaryTree(TreeNode* root) {
//         if(root==NULL){
//             return 0;
//         }
    
//         queue<pair<TreeNode*,unsigned long long   > > q;
//         q.push({root,0});

//         unsigned long long  width=0;
//         while(!q.empty()){
//             // the first and last of any level
//             auto left = q.front().second;
//             auto right = q.back().second;

//             unsigned long long width = max(width,right-left+1);
//             int n =q.size();
//             while(n--){
//                 TreeNode* curr = q.front().first;
//                unsigned long long  idx = q.front().second;
//                 q.pop();
//                 if(curr->left){
//                     q.push({curr->left,2*idx+1});
//                 }
//                 if(curr->right){
//                     q.push({curr->right,2*idx +2});
//                 }

//             }

//         }
//     return width;
//     }
// };
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        typedef unsigned long long ll;
        queue<pair<TreeNode*,unsigned long long > > q;
        q.push({root,0});
        unsigned long long width=0;
        while(!q.empty()){
            ll left = q.front().second;
            ll right = q.back().second;

            width = max(width,right-left+1);
            ll n=q.size();
            while(n--){
                TreeNode* curr = q.front().first;
                ll idx = q.front().second;
                q.pop();
                if(curr->left){
                    q.push({curr->left,2*idx+1});
                }
                if(curr->right){
                    q.push({curr->right,2*idx +2});
                }

            }

        }
    return width;
    }
};