/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    queue<string> tokenise(string data){
        queue<string> res;
        int start =0;
        int end = data.find(",");
        while(end!=-1){
            string str = data.substr(start, end-start);
            res.push(str);
            start = end+1;
            end = data.find(",", start);
        }
        return res;

    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "NULL";
        string res="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto p= q.front();
            q.pop();

            if(p){
                res+=to_string(p->val)+",";
                q.push(p->left);
                q.push(p->right);

            }
            else
            res+="NULL,";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
        if(data.size()==0 || data=="NULL") return NULL;
        queue<string> d = tokenise(data); 
        int x = stoi(d.front());
        TreeNode* root = new TreeNode(x);
        d.pop();

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty() ) {
            auto p = q.front();
            q.pop();
            if(!p) continue;
            string s = d.front();
            d.pop();
            if(s!="NULL"){
                int val = stoi(s);              
                p->left = new TreeNode(val);
            }
            else p->left = NULL;
            q.push(p->left);
            
            if(d.empty()) break;

            
            s = d.front();
            d.pop();
            if(s!="NULL"){
               int val= stoi(s);              
                p->right = new TreeNode(val);
            }
            else p->right = NULL;
            q.push(p->right);
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));