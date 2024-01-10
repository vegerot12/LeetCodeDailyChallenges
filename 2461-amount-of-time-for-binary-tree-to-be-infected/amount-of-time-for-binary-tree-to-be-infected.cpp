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

unordered_map<int, vector<TreeNode*>> e;
unordered_set<int> vis;
int time=0;

void makeGraph(TreeNode* root){
    if(!root) return ;

    if(root->left){
    e[root->val].push_back(root->left);
    e[root->left->val].push_back(root);
    }
    if(root->right){
    e[root->val].push_back(root->right);
    e[root->right->val].push_back(root);

    }

    makeGraph(root->left);
    makeGraph(root->right);


    
}
// now becomes rotten orange
void checkTime(TreeNode* root)
{
  

    queue<TreeNode*> q;
    q.push(root);
    vis.insert(root->val);

    while(!q.empty()){
      
        int s = q.size();
        while(  s--){
        auto p = q.front();
        q.pop();

        for(auto src: e[p->val] ){
        if(vis.find(src->val) == vis.end()){     
            vis.insert(src->val);
            q.push(src);
        }
        }
        }

        if(!q.empty())   time++;

    }
}

void checkStart(TreeNode* root, int start){
    if(!root) return;

    if(root->val == start){
       
        return checkTime(root);
    }

    checkStart(root->left, start);
    checkStart(root->right, start);
}
    int amountOfTime(TreeNode* root, int start) {
        makeGraph(root);
        
        checkStart(root, start);
        return time;
   
    }


};