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

 /*
 can be pal
- if len == 1 
- if the cnt of each char is even except for atmost  1 
- find all root to leaf paths and check for pal 
// O(n) and O(n)


class Solution {
public:
    bool isPal(unordered_map<int, int>& m){
        int odd = 0;
        for(auto it:m){
            if(it.second%2) odd++;
            if(odd >1) return false;
        }

        return true;
    }

    void findPath(TreeNode* root, int& res, vector<int>& path, unordered_map<int, int>& m ){
        if(!root) return;

        path.push_back(root->val);
        m[root->val] ++;

        // leaf
        if(!root-> left && !root->right){
            if(isPal(m)) res++;
        } 

        findPath(root->left, res, path , m);
        findPath(root->right, res, path , m);

        path.pop_back();
        m[root->val]--;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path;
        unordered_map<int, int> m;
        int res =0;
        findPath(root, res, path , m);
        return res;
    }
};
 */


 // OPTIMISATION 

class Solution {
public:
   

    void findPath(TreeNode* root, int& res, unordered_map<int, int>& m, int& odd ){
        if(!root) return;

        
        m[root->val] ++;
        int odd_change =  m[root->val] % 2 ? 1 : -1;
        odd += odd_change; // we increase or decrease odd based on cur num 


        // leaf
        if(!root-> left && !root->right){
            if(odd<=1) res++;
        } 

        findPath(root->left, res,m, odd);
        findPath(root->right, res, m, odd);

        odd -= odd_change; // if we increased before while removing that num we decrease and vice versa 
        m[root->val]--;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
       
        unordered_map<int, int> m;
        int res =0, odd=0;
        findPath(root, res, m, odd);
        return res;
    }
};