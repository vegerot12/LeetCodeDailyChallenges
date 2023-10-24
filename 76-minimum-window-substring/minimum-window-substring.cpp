class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;

        for(auto c:t){
            m[c]++;
        }
        int n1= s.size(), n2 = t.size();
        int st=0, e=0, bs=0, len = n1+1 , tot = n2;

        while(e<n1){
            
            if(m.find(s[e])!= m.end()){
                if(m[s[e]]>0) tot--;
                m[s[e]]--;
                
            }

            while(tot == 0 ){
          
                if(m.find(s[st])!= m.end()){
                    if(len> e-st+1){
                         len = e-st+1;
                         bs = st;
                    }
                
                if(m[s[st]] == 0) tot++;
                m[s[st]]++;
               
            }
             st++;
            }

            e++;
        }
        if(len > n1) return "";
        return s.substr(bs, len);
    }
};