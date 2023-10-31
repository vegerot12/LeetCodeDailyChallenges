class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;

        }

        queue<int> q;

        for(int i =0;i<n;i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }

        vector<int> res;

        while(!q.empty()){
           
           int s = q.size();
           res.clear();
           while(s--){
                auto p = q.front();
            q.pop();

            res.push_back(p);

            for(auto& nei:adj[p]){
               
                indegree[nei]--;
                if(indegree[nei] == 1)
                {
                     q.push(nei);
                }
            }

           }


        }
        return res;
    }
};