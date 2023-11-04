class Solution {
public:
    void dfs(string& digits,unordered_map <char, string>& m,  vector<string>& res, string& cur, int ind ){
        if(ind == digits.size()) {
            res.push_back(cur);
            return ;
        }

       
            for(char c: m[digits[ind]]){
                cur.push_back(c);
                dfs(digits,m,res,cur,ind+1);
                cur.pop_back();
            }
        
    }
    vector<string> letterCombinations(string digits) {
        unordered_map <char, string> m ;
            m.insert({'2',"abc"});
             m.insert({ '3', "def"});
              m.insert({'4',"ghi"});
               m.insert({'5',"jkl"});
                m.insert( {'6',"mno"});
                 m.insert({'7',"pqrs"});
                 m.insert({'8',"tuv"});
                  m.insert({'9',"wxyz"});
                  

        vector<string> res;
        if(digits.size() == 0) return res;
        string cur;
        // int ind  =0;

        // dfs(digits, m, res,cur,ind);

    res.push_back("");

        for(int i=0;i<digits.size();i++){
            vector<string> cur;
                 for( auto c: m[digits[i]] ){
            for(string s:res){
                cur.push_back(s+c);
            }
            }
            res=cur;
           
        }
        return res;
        
    }
};