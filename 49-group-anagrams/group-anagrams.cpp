class Solution {
public:

string sorted(string s){
    int charMap[26] = {0};

    for(char c:s){
        charMap[c-'a']++;
    }

    string t;
    for(int i=0;i<26;i++){
        t+= string(charMap[i], i+'a');
    }
    return t;
}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; // sorted str, list of str

        for(auto& s:strs){
            mp[sorted(s)].push_back(s);
        }

        vector<vector<string>> res;

        for(auto &it : mp){
            res.push_back(it.second);
        }
        return res;

    }
};