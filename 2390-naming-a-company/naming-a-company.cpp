class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> s[26], res;
         long long cnt = 0;
        int n = ideas.size();

         for(int i=0;i<n;i++){
             s[ideas[i][0]-'a'].insert(ideas[i].substr(1));
         }


        for(int i=0;i<25;i++){
            // fpr each in set i with each in other 25 sets 
            for(int j=i+1;j<26;j++){
                long long mutual=0;
                for(auto& p:s[j]){
                    if(s[i].find(p) != s[i].end())
                    mutual++;
                }
            //     
               
                cnt+= ((s[i].size()-mutual )*( s[j].size() - mutual ));
                // cnt +=  ((s[i].size() -mutual) * (s[j].size()-mutual));


            }
        }
        
    // for(int i=0;i<25;i++){
    //         for(int j=i+1;j<26;j++){
    //            // find mutual
    //            int mutual =0;
    //            for(auto& p: s[j]){
    //                 if(s[i].find(p) != s[i].end())
    //                 mutual++;
    //            }
    //             // find valid names
    //             // each pair of valid suffix will lead to two names- ab and ba  so 2* cnt
    //             cnt += 2* ((s[i].size() -mutual) * (s[j].size()-mutual));

    //         }
    //     }
return cnt*2;
    }
};