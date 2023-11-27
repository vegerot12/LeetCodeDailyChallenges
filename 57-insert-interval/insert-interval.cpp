class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& it, vector<int>& nit) {
        bool added = false;
        int s=0, n = it.size();

        for(int i =0;i<n;i++){
            if(nit[1]< it[i][0]){
                it.insert(it.begin()+i, nit);
                added = true;
                break;
            }
            else{
                if(max(it[i][0], nit[0]) <= min( it[i][1], nit[1])){

                    // s=i,e=i;
                while(i<n && max(it[i][0], nit[0]) <= min( it[i][1], nit[1])){
                   nit[0] = min(nit[0], it[i][0]);
                   nit[1] = max(nit[1], it[i][1]);
                  
                   i++;
                   s++;

                }
 it.erase(it.begin()+i-s, it.begin()+i  );
                it.insert(it.begin()+i-s, nit );
                added = true;
                break;

                }

            }
        }

        if(!added)
        it.push_back(nit);
        return it;
    }
};