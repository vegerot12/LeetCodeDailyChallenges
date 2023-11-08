class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          vector<vector<int>> res;
        priority_queue< array<int,2>, vector<array<int,2>>  , greater<array<int,2>>> pq;
        int i =0;
        for(auto &p : points){
            pq.push({ p[0]*p[0] + p[1]*p[1],i++ });
        }

        while(!pq.empty() and k--){
            auto p = pq.top();
            pq.pop();
            res.push_back(points[p[1]]);
            
        }

        return res;
    }
};