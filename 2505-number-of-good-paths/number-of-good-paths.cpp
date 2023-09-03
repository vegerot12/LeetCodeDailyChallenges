class Solution {
    // unionParent 
    int ds_find(int i, vector<int>& parent) {
        if (parent[i] != i)
            parent[i] = ds_find(parent[i], parent);
        return parent[i];
    }
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        // Sort edges bsed on node values, 
        sort(edges.begin(), edges.end(),
            [&](vector<int>& l, vector<int>& r) {
                return max(vals[l[0]], vals[l[1]]) < max(vals[r[0]], vals[r[1]]);
            });
        
        // Count or size of each grp
        vector<int> cnt(vals.size(), 1);
        
        // DS parent
        vector<int> parent(vals.size());
        for (int i = 0; i < vals.size(); ++i)
            parent[i] = i;

        int ans = vals.size();

        // in the sorted edges we do union 
        for (auto& e: edges) {
            int a = ds_find(e[0], parent);
            int b = ds_find(e[1], parent);
            // if not same val we cant join these nodes 
            if (vals[a] != vals[b]) { 
                if (vals[a] > vals[b]) // so we make a edge from larger to smaller 
                    parent[b] = a;
                else
                    parent[a] = b;
            } else { // same val so we put in same comp and this here will form a good path so we add the cnt 
                parent[a] = b;
                ans += (cnt[a] * cnt[b]); // no of nodes with parent as a and parent as b 
                cnt[b] += cnt[a];
            }
        }

        return ans;      
    }
};