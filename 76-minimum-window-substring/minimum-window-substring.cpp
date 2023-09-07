class Solution {
public:
    string minWindow(string s, string t) {
        // 
        int n1= s.size() , n2 = t.size();
        if(n1<n2) return "";
        unordered_map<char, int> m;
        for(auto tt:t){
            m[tt]++;
        }

        int st=0, e=0, len = n1+1, tot = n2, bestStart=0;

        while(e<n1){
            // find winodw move e 
             
              if(m.find(s[e])!= m.end()){ // if char at e is in p
            m[s[e]]--;
            if(m[s[e]]>=0){
               
                tot--;
            }
              }
            // if we got window optimsie it 
            while(tot == 0){
                if(m.find(s[st]) !=m.end()){
                    if(len > e-st+1){
                    len = e-st+1;
                    bestStart = st;
                }
                 if(m[s[st]]==0){
                        

                   
                    tot++;
                }
                  m[s[st]]++;
                }
               
               
               
                st++;
            }
            e++;
        }
        if(len > n1) return "";
        return s.substr(bestStart,len);
    }
};