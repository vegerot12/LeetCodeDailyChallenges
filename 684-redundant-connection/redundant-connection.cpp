  class Solution {
    private:
    int find(int p,vector<int>& parent){

        if(parent[p] == p) return p;
        return parent[p] = find(parent[p],parent);
    //   if(parent[p]!=p)
    //   parent[p] = find(parent[p],parent);
    //   return parent[p];
    }

    int unionEdge(int a, int b, vector<int>& parent){
        int p1 = find(a,parent);
        int p2 = find(b, parent);
        if(p1==p2) return -1; // if it already has same parent return -1 meaning this node has to be removed
        return parent[p1]=p2; // if they both have diff parent since there exisits a edge between them now make it as same parent 
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); // graph has been started as a tree(tree of n nodes has n-1 edges) and one edge got added extra in the graph - so n-1+1 = the graph has n edges , and n nodes

        vector<int> parent(n+1); // since nodes from 1 to n
       // initialise parent as itself
       for(int i=1;i<=n;i++) 
       parent[i] =i;

       // for each of n edges chek if any edge has same parent
       for(int i=0;i<n;i++){
           int x = unionEdge(edges[i][0], edges[i][1], parent); // keep merging nodes connected by each of n edges 
           // when we come across a nodes that already are connected return that edge as it is not needed
           if(x==-1) return edges[i];
       }
       return edges[n-1];
    }
};