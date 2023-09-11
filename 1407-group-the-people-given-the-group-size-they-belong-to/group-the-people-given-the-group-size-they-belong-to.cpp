/*

Put the person i in the group of size groupSize[i] 
TC : O(n) and SC = 2*O(n) - map and vector res ;
*/

class Solution {
public:

    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n= groupSizes.size(); 
        vector<vector<int>> res;
        map<int, vector<int>> g;

        for(int i=0;i<n;i++){ // O(n)
          auto& grp =  g[groupSizes[i]];
           grp.push_back(i);
           if(grp.size() ==  groupSizes[i]){
               res.push_back(grp);
               grp.clear();
           }
        }

       
        return res;
    }
};