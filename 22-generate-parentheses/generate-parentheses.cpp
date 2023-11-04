class Solution {
public:
    void dfs(vector<string>& res,string& cur,int ind, int n, int& open, int& close){
        if(ind == 2*n){
            res.push_back(cur);
            return;
        }

        if(open < n ){
            open++;
            cur += '(';
            dfs(res,cur, ind+1, n, open, close);
            cur.pop_back();
            open --;
        }
        if(open > close ){
             close++;
            cur += ')';
            dfs(res,cur, ind+1, n, open, close);
            cur.pop_back();
            close --;
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur;
         vector<string> res;
         int ind =0;
         int open = 0, close = 0;
         dfs(res,cur,ind,n, open , close);
         return res;
    }
};