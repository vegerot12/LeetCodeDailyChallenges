class DSU {
    private:
    vector<int> parent;
    vector<int> size;

    public:
    DSU(int n){
        parent.resize(n,-1);
        size.resize(n,0);
    }

    int findParent(int x){
        if(parent[x] == -1 ) return x;
        return parent[x] = findParent(parent[x]);
    }

    void findUnion(int x, int y){
        int px = findParent(x);
        int py = findParent(y);
if(px == py){
          return;
      }
        if(size[px] < size[py]){
            parent[px] = py;
            size[py] += size[px];
        }
        else {
            parent[py] = px;
            size[px] += size[py];
        }

    }



};

class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        int n = a.size();
        // consider idx as ID
        // emailid to idx map
        unordered_map<string, int> emailToId;
        unordered_map<int, vector<string>> IdToEmails;

        DSU dsu(n);

        for(int i =0;i<n;i++){
          
          for(int j = 1;j<a[i].size();j++){
              if(  emailToId.find(a[i][j]) == emailToId.end()){
                 emailToId[a[i][j]] = i;
              }
              else {
                  dsu.findUnion(i, emailToId[a[i][j]]);
              }

          }
        }


        // id to emails
        for(auto m:emailToId){
            int id = m.second;
            string email = m.first;

            int grpId = dsu.findParent(id);

            IdToEmails[grpId].push_back(email);

        }


        // res iwth name 

        vector<vector<string>> res;

       

        for(auto grp: IdToEmails){
            int id= grp.first;
            auto& emails = grp.second;

            vector<string> curGrp;
            curGrp.push_back(a[id][0]); // name
            sort(emails.begin() , emails.end());


            
           curGrp.insert(curGrp.end(),emails.begin(), emails.end());
            res.push_back(curGrp);
        }

        return res;
    }
};