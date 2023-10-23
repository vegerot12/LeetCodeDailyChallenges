class Solution {
public:
bool isPal(string w){
    int i =0, j=w.size()-1;
            while(i<j){
                if(w[i++] != w[j--]){
                    return false;
                }
            }
            return true;
        }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> s;
         vector<vector<int>> res;

        for(int i =0;i<words.size();i++){
            string t = words[i];
            reverse(t.begin(), t.end());
            s.insert({t,i});

        }

        if(s.find("")!=s.end()){
            for(int i = 0;i<words.size();i++){
               if(words[i]!="" && isPal(words[i])){ 
                   res.push_back({s[""], i});
               }
            }
        }        

        for(auto i =0;i<words.size();i++){
            // split the string into many parts and check if left is in map and right is a pal , 
            for(int j=0;j<words[i].size();j++){
                string left = words[i].substr(0,j);
                string right = words[i].substr(j);
                if(s.find(left) != s.end() && isPal(right)&& s[left]!= i){
                    res.push_back({  i,s[left]});
                }
                if(s.find(right) != s.end() && isPal(left)&& s[right]!=i){
                    res.push_back({ s[right], i});
                }
            }
             
             
        }
return res;
    }
};