class Solution {
public:
bool isUnique(string cur){
     unordered_set<char> s;
     for(auto& c:cur){
         if(!s.insert(c).second) return false;
     }
     return true;
}
    int dfs(vector<string>& arr, string cur, unordered_map<string, int>& dp, int &res , int ind ){
        if(dp[cur]) return dp[cur];

        if(!isUnique(cur)) return 0;

        res = max(res, int(cur.size()));

        if(arr.size() == ind)return dp[cur];
// We pass i+1 because if we pass ind+1 then there is a possibility that it ind+1 can be equal to i and it might mean adding the same chars again , so to make sure we add unique chars we do i+1 for next iteration meaning we start checkig from i+1 
        for(int i=ind;i<arr.size();i++){
           dp[cur]= dfs(arr, cur+arr[i], dp, res, i+1);
        }

        return dp[cur] ;




    }
    int maxLength(vector<string>& arr) {
        unordered_map<string, int> dp;
        int res = 0;
        string cur = "";
        dfs(arr, cur, dp, res, 0);
        return res;
    }
};