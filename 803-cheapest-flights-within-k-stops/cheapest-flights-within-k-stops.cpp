class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {

        vector<vector<int>> adj[n];

        for(auto cf : f){
            adj[cf[0]].push_back({cf[1],cf[2]});
        }

        vector<int> cost(n,INT_MAX);
        cost[src] = 0;
// we dont need a Pq it is based on stops , our first pref is no of stops , and it is increasing by 1 alwaus so we deal like a normal BFS, if we go with PQ additional log n for every push and pop
       queue<array<int,3>> q; // { stops, node, cost}
        q.push({0,src,0 });

        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto p = q.front();
                q.pop();
                int hopsSoFar = p[0], curNode = p[1], costSoFar = p[2];
                
                if(hopsSoFar > k ) continue;

                for(auto& nei: adj[p[1]]){
                    // cout<<(nei[1] + costSoFar < cost[nei[0]])<<endl;
                    if(cost[nei[0]] > costSoFar+ nei[1]    ){ //
                        cost[nei[0]] =costSoFar+ nei[1];
                        q.push({hopsSoFar+1 ,   nei[0],costSoFar+ nei[1]});
                       
                    }
                }


            }
        }
        
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};