class Solution {
public:
   
    vector<int> findAnagrams(string s, string p) {

//         if(s.size() < p.size()) return {};
//         unordered_map<int,int> m;
//         vector<int> res;

//         for(int i =0;i<p.size() ;i++){
//             m[p[i]-'a']++;
            
//         }
                

// int i = 0, match =0;
// int r = 0;

//         while( r<s.size()){
            
//             if(m.find(s[r]-'a') != m.end()){
//               m[s[r] - 'a']--;
//               cout<<s[r]<<m[s[r]-'a']<<endl;
//               if(m[s[r]-'a'] == 0) match++;
              
//             }
//             // cout<<match<<endl;
//                 r++;
//             if(match == m.size()) res.push_back(i);
//             if(r >= p.size()-1 ){
//               if(m.find(s[i]-'a') != m.end()){
//               if(m[s[i]-'a'] == 0) match--;
//               m[s[i] - 'a']++;

//             }
//             i++;
//             }

             
         
           

            
            
//         }
//         return res;
   

        vector<int> res;
        int st = 0;
        int matched = 0;
        unordered_map<char, int> m;

        for (int i = 0; i < p.size(); i++) {
            m[p[i]]++;
        }

        for (int e = 0; e < s.size(); e++) {
           

            if (m.find(s[e]) != m.end()) {
                m[s[e]]--;

                if (m[s[e]] == 0) {
                    matched++;
                }
            }

            if (matched == (int)m.size()) {
                res.push_back(st);
            }

            if (e >= p.length() - 1) {
               

                if (m.find(s[st]) != m.end()) {
                    if (m[s[st]] == 0) {
                        matched--;
                    }

                    m[s[st]]++;
                }
                st++;
            }
        }

        return res;
    }
};
      
  