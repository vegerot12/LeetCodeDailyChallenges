class Solution {
public:

// int shortestPathLength(vector<vector<int>>& graph) {
//         queue<vector<int>> q;  //  {node, maskedBit, len} -- stores node info 
//         set<pair<int,int>> vis; // {node, maskedbit} -- stores node and the path from it 
//         int n = graph.size();
//         int all = (1<<n)-1; // all nodes visited
//         for(int i =0;i<n;i++){
//             int mask = 1<<i;
//             int len = 1; // initial cost or path length
//             q.push({i,mask,len});
//             vis.insert({i,mask});
//             cout<<mask<<endl;
//         }
        
//         // bfs
//         while(!q.empty()){
//             auto p = q.front();
//             q.pop();
//             int cur = p[0];
//             int mask = p[1];
//             int len = p[2];
            
//             if(mask==all)return len-1;
            
//             for(auto node:graph[cur]){
//                 int maskedPath = mask | (1<<node);
//                 if(vis.find({node,maskedPath}) == vis.end()){
//                     q.push({node,maskedPath,len+1});
//                     vis.insert({node,maskedPath});
//                 }
//             }
//         }
//         return -1;
        
        
//     }


    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        queue<vector<int>> q; // node , bitmask, len 
        set<pair<int,int>> vis; // node , bitmask

        int all = (1<<n) -1;
        

        for(int i =0;i<n;i++){
            int mask = 1<<i;
            q.push({ i, mask,1});
            vis.insert({ i, mask});
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int node = p[0];
            int mask = p[1];
            int len = p[2];

            if(mask == all) return len-1;

            for(auto adj: graph[node]){
               int  newMask = mask | (1<<adj);
                if(vis.find({adj, newMask})== vis.end()){
                    vis.insert({adj, newMask});
                    q.push({adj, newMask, len+1});
                }
            }

        } 
        
        return -1;

    }
};