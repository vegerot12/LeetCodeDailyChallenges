class Solution {
public:
int dfs(string& s, string& t, int i, int j, int n,int m,  map<pair<int,int>, int>& cache){
    if(j==m ) return 1;
    if(i ==n) return 0;

    if(cache.find({i,j})!= cache.end()){
        return cache[{i,j}];
    }
    // if(s[i]==t[j])
    // cache[{i,j}] = dfs(s,t,i+1,j+1,n,m,cache) + dfs(s,t,i+1,j,n,m,cache);
    // else
    // cache[{i,j}] = dfs(s,t,i+1,j,n,m,cache);
      if(s[i]==t[j])
    cache[{i,j}] = dfs(s,t,i+1,j+1,n,m,cache) ;
    
    cache[{i,j}] += dfs(s,t,i+1,j,n,m,cache);

    return cache[{i,j}];


}
// how many subsequences of s equals to t 
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size();
        if(m==0) return 1; // if t is empty "" subsequence of s  matches full of t which is ""
        if(n==0) return 0; // if s is empty only one subsequence "" exists in s and we cant match whole of t with that so 0

        map<pair<int,int>, int> cache;

       return dfs(s,t, 0, 0, n,m,cache);

        
    }
};