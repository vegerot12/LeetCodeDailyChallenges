// Perform union Edge func --  O(α(N)) , and w call it for n times so      n*O(α(N)) and SC is O(n)
class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    int components;

    DSU(int n){
        parent.resize(n+1,-1); // node strts from 1 to n so n+1 
        size.resize(n+1,1);
        components = n;
       
    }

    int findParent(int x){
        
        if(parent[x]==-1) return x; 
        return parent[x] = findParent(parent[x]);
    }

    bool unionEdge(int x, int y){
        int px = findParent(x);
        int py = findParent(y);

        if(px==py) return false; // union not happend alrd connected so false
       
        if(size[px] > size[py]){
        parent[py] = px; // x is big so it should be parent
        size[px] += size[py];
        }
        else{
        parent[px] = py;
        size[py] += size[px];
        }

       components--; // we performed union and linked two nodes so disconnected comp cnt decreased
        return true; // union happened so true

    }

    bool isConnected ( ){
        return components == 1;
    }

    
};

class Solution {
   
   
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // create two DSU objects
        // G1: perform union of edges of type 1 and 3
        // G2: perform union of edges of type 2 and 3

        DSU alice(n), bob(n);
        int edgeNeeded = 0;

    // First do all type 3 as both can use it - do union of type 3 in both graphs
        for(auto& e:edges){
          if(e[0] == 3){
              cout<<"t1"<<e[1];

              // if two nodes are alrd connected it returns false else true so even if one of the two alice or bob preformed union then this edge is needed so we use || and inc 
              edgeNeeded += (alice.unionEdge(e[1], e[2]) | bob.unionEdge(e[1], e[2]));

          }

        }
        // now build type 1 for alice and type 2 for bob 
        for(auto& e:edges){
          if(e[0] == 2){
              // if two nodes are alrd connected it returns false else true so even if one of the two alice or bob preformed union then this edge is needed so we use || and inc 
              edgeNeeded += (bob.unionEdge(e[1], e[2]) );

          }
          else if(e[0]==1){
                edgeNeeded += (alice.unionEdge(e[1], e[2]) );
          }

        }

        // if both are connected we have remobed edges correctly so find the no of removede edges
        if(alice.isConnected() && bob.isConnected())
        return edges.size()-edgeNeeded;

        return -1;



        

        
    }
};