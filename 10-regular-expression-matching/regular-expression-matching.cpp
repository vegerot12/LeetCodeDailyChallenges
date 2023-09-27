class Solution {
public:
/*

S = "aab" i 
P = "c*a*b". j 

if we skip the * and its preceding char we keep the i same and j=j+2
if we take the * and its preceding char we keep the j same and i = i+1

backtracking = O(2^n) because each char can be taken or not taken
but using DP = O(m*n)

*/
    bool dfs(string& s, string& p, int i, int j, int& n, int& m,  map<pair<int, int>, bool>& dp){
        if(dp.find({i,j}) != dp.end()) return dp[{i,j}];

        if(i>=n && j>=m) return true;

        if(j>=m) return false;

        // 1. see if the cur chars match or if cur pattern has a .
        bool match = i<n && (s[i] == p[j] || p[j] =='.');

        // 2. see if the next pattern char is a *  
        // if true we have to decide here 
    
        if(j+1< m && p[j+1] == '*'){
            bool dontUseStar = dfs(s,p,i,j+2,n,m, dp); // dont use * keep i same,
            bool useStar = match && dfs(s,p,i+1, j,n,m, dp); // we can use the star and put atleast one char of * only if cur matches , so if amtch is true and then we can use star so our cur str got match so we move str ptr i by 1 and keep pattern same
             return dp[{i,j}] = dontUseStar || useStar;

        }

        // 3. if next is not a star
        // if cur matched inc both since next pattern char is a straighforward so decision here 
        if(match){
         dp[{i,j}] = dfs(s,p, i+1, j+1, n, m, dp);
 return dp[{i,j}];
        } 

        // 4. if cur didnt match next also is a not a * so chance of matching at all so return false
       dp[{i,j}] = false ;
       return dp[{i,j}];

    }
    
    bool isMatch(string s, string p) {
        int i=0, j=0, n = s.size(), m = p.size();
        map<pair<int, int>, bool> dp; 
       return dfs(s,p,i,j,n,m, dp);
       
    }
};