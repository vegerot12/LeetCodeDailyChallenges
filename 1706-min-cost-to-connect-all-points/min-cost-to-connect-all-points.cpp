class DSU {
    private:
    vector<int> parent;
    vector<int> size;
    int con =0;
    public:
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++)
        parent[i] = i;
        size.resize(n,1);
        con =n;
    }
    int findParent(int x){
        if(parent[x] ==x) return x;
        return parent[x] = findParent(parent[x]);
    }
    bool unionFind(int x,int y){
        int px = findParent(x);
        int py = findParent(y);

        if(px == py)
        return false;

        if(size[px] < size[py]){
            size[py] += size[px];
            parent[px] = py;
        }else{
           size[px] += size[py];
            parent[py] = px; 
        }
        return true;
    }
    bool isConnected(){
        return con==1;
    } 

    
};
class Solution {

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        

int n = points.size(), res=0;
DSU dsu(n);
// priority_queue<array<int,3>> pq; // dis, i, j
vector<array<int,3>> pq;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i!=j){
            pq.push_back({ -(abs(points[i][0] - points[j][0]) +abs(points[i][1] - points[j][1] )), i, j});
        }
    }

}
make_heap(pq.begin(), pq.end());  // O(n) heapify

// k times to pop k ele from heap - k log n
while(!pq.empty() && !dsu.isConnected() ){
    // auto p = pq.top();
    pop_heap(begin(pq), end(pq));
    auto p = pq.back();

    pq.pop_back();
    if(dsu.unionFind(p[1], p[2])){
        res+= -p[0];

    }
}
return res;
    }
};