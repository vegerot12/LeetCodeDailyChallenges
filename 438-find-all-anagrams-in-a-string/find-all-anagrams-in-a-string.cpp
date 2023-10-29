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
   

        vector<int> anagrams;
        int windowStart = 0;
        int matched = 0;
        unordered_map<char, int> charFrequencyMap;

        for (int i = 0; i < p.length(); i++) {
            charFrequencyMap[p[i]]++;
        }

        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
            char right = s[windowEnd];

            if (charFrequencyMap.find(right) != charFrequencyMap.end()) {
                charFrequencyMap[right]--;

                if (charFrequencyMap[right] == 0) {
                    matched++;
                }
            }

            if (matched == (int)charFrequencyMap.size()) {
                anagrams.push_back(windowStart);
            }

            if (windowEnd >= p.length() - 1) {
                char left = s[windowStart++];

                if (charFrequencyMap.find(left) != charFrequencyMap.end()) {
                    if (charFrequencyMap[left] == 0) {
                        matched--;
                    }

                    charFrequencyMap[left]++;
                }
            }
        }

        return anagrams;
    }
};
      
  