class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;

        for(auto& c:t){
            m[c]++;
        }

        int start=0, bestStart = 0, total = m.size(), res=INT_MAX;

        for(int i =0 ;i<s.size() ; i++){
         if(m.find(s[i]) != m.end()){

            m[s[i]]--;
            // if becomes 0 dec toatl
            if(m[s[i]]==0){
                total --; 
            }
         }   
                while(total == 0){

                    if(m.find(s[start]) != m.end()){
   if(i-start+1 < res){
                   bestStart = start;
                   res =i - start +1;

               }
                                 //  we move start ptr to minimise 

              
                if(m[s[start]] == 0) total ++;
                  m[s[start]]++;
                
               

                }
                start ++;
                    }
            





            
        }
        if(res > s.size()) return "";
        return s.substr(bestStart, res);
    }
};