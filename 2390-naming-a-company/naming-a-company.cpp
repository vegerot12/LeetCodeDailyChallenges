class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> s[26], res;
         long long cnt = 0;
        int n = ideas.size();

         for(int i=0;i<n;i++){
             s[ideas[i][0]-'a'].insert(ideas[i].substr(1));
         }


        for(int i=0;i<26;i++){
            // fpr each in set i with each in other 25 sets 
            for(int j=i+1;j<26;j++){
                long long c1 =0, c2=0;
                for(auto& p:s[i]){
                    if(s[j].find(p) == s[j].end())
                    c1++;
                }
                for(auto& p:s[j]){
                    if(s[i].find(p) == s[i].end())
                    c2++;
                }
                cnt+= c1*c2;


            }
        }
        return cnt*2;
    }
};