class Solution {
public:
    bool isSame(int  m[26],int sm[26]){
        for(int i =0;i<26;i++){
            cout<<m[i]<<sm[i]<<endl;
            if(m[i] != sm[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {

        if(s.size() < p.size()) return {};
        int  m[26]={0}, sm[26]={0};
        vector<int> res;

        for(int i =0;i<p.size() ;i++){
            m[p[i]-'a']++;
            sm[s[i]-'a']++;
        }
                

int i = 0;
        for( i =0;i<s.size()- p.size();i++){
            int r = i+p.size();

            if(isSame(sm,m)) res.push_back(i);

            sm[s[i] - 'a']--;
            sm[s[r] - 'a']++;
        }
        if(isSame(sm,m)) res.push_back(i);
        return res;

      
    }
};