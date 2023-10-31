class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> dep(n);
        vector<int> indeg(n,0);
        queue<int> q;
        int cnt = 0;

        for(auto &p : pre){
            dep[p[1]].push_back(p[0]);
            indeg[p[0]] ++;

        }

        for(int i=0;i<n;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            cnt++;

            for(auto d:dep[p]){
                indeg[d]--;
                if(indeg[d]==0){
                    q.push(d);
                }
            }
        }
        return cnt == n;
    }
};