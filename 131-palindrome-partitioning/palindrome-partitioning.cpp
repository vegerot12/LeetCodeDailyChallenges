class Solution {
public:
bool isPal(const string& s, int a, int b) {
    
     while (a < b) {
            if (s[a] != s[b]) {
                return false;
            }
            a++;
            b--;
        }
        
        return true;
    }
void dfs(string s, int ind,vector<vector<string>>& res,
        vector<string>& tmp){
           
            
        if(ind == s.size()){
            res.push_back(tmp);
        return;

        } 
//  our main intention is to make sure we dont include same ele in any given subsets from level so we do nums[i] == nums[i-1] continue . But we also want to include it in different subset even if nums[i] == nums[i-1] they can be very well part of different subsets from different level of recursion, and if we use this condiiton alone then we may not be able to use them in next subset also so to restrict or channelise this condition properly we also check if i != ind  and nums[i] == nums[i-1] continue which means that if i==ind we are starting a new level and we should ignore about nums[i] == nums[i-1] .
        for(int i=ind;i<s.size();i++){
             if(isPal(s, ind, i)) 
            {

            tmp.push_back(s.substr(ind,i-ind+1));
           
            dfs(s,i+1, res, tmp);
            tmp.pop_back();
           

             }
             
        }


    }
  
    vector<vector<string>> partition(string s) {
         vector<vector<string>> res;
        vector<string> tmp;
        dfs(s,0, res,tmp);
        return res;
    }
};