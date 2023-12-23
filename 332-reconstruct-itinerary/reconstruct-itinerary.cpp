class Solution {
    private:
          unordered_map<string,priority_queue<string, vector<string>, greater<>>> adj;
          vector<string> res;
          void dfs(string src){
             while( adj.find(src) != adj.end() && !adj[src].empty()){
                 auto node = adj[src].top();
                 adj[src].pop();
                 dfs(node);
             }
             res.push_back(src);
          }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
         // sort(tickets.begin(), tickets.end());
          for(auto& t:tickets){
              adj[t[0]].push(t[1]); // tickets are diretced edges
          }
          int n = tickets.size();
          dfs("JFK" );
          reverse(res.begin(), res.end());
          return res;
    }
};