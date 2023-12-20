class DSU{

    vector<int> parent, size;

    public:
    DSU(int n){
        parent.resize(n,-1);
        size.resize(n,1);
    }


    int findParent(int x){
        if(parent[x] == -1)  return x ;
        return parent[x] = findParent(parent[x]);
    }

    bool unionParent(int x, int y){
        x = findParent(x);
        y = findParent(y);

        if( x == y) return false;

        if(size[x] > size[y]){
        parent[y] = x;
        size[x] += size[y];
        }
        else {
            parent[x] = y;
            size[y] += size[x];
        }
return true;
    }
    
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         int n =edges.size();
        DSU dsu(n+1);
        vector<int> res;
        
        for(auto e:edges){
            if(!dsu.unionParent(e[0], e[1]))
            res = e;

        }
        return res;
    }
};