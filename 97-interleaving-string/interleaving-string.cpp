class Solution {
public:
    bool dfs(string& s1, string& s2, string& s3, map<pair<int,int>, bool> & dp, int i , int j){
        if(i==s1.size() && j==s2.size()) return true;
          if (dp.find({i, j}) != dp.end()) {
            return dp[{i, j}];
        }


        if(i<s1.size() and s1[i] == s3[i+j] and dfs(s1,s2,s3,dp, i+1, j)) return dp[{i, j}]= true;

        if(j<s2.size() and  s2[j] == s3[i+j] and dfs(s1,s2,s3,dp, i, j+1)) return dp[{i, j}]= true;

       dp[{i,j}] = false;
        return dp[{i,j}];
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() < s3.size()) return false;

    map<pair<int, int>, bool> dp;
       return dfs(s1,s2,s3,dp,0,0);
    }
};

// for(int i =0;i<s1.size();i++){
//             for(int j =0;j<s2.size();j++){
//                 if(s1[i]==s3[i+j] || s2[j]==s3[i+j]){
                    
//                 }
//             }
//         }