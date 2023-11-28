class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& it, vector<int>& queries) {
               vector<int> q = queries; // copy of queries

        sort(it.begin(), it.end());
        sort(queries.begin(), queries.end());


        unordered_map<int,int> qRes;
        priority_queue<pair<int,int>> durationEnd; 

            int i =0;
        for(auto q:queries){

            while(i< it.size() and it[i][0] <= q ){
                durationEnd.push({ -(it[i][1] - it[i][0] +1) ,it[i][1] });
                i++;
            }

            while(!durationEnd.empty() and durationEnd.top().second < q){
                durationEnd.pop();
            }

            qRes[q] = durationEnd.empty() ? -1 : -1*durationEnd.top().first;
            cout<<q<<qRes[q]<<endl;



        }
         vector<int> res(queries.size());
         i=0;
         for(auto qr:q){
             res[i++] = qRes[qr];
         }

         return res;

    }
};