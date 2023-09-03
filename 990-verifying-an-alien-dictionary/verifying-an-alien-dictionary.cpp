class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> lex;
        for(int i =0;i<26;i++){
            lex[order[i]] = i;
        }

        for(int i=0;i<words.size()-1;i++){
            int curSize = min(words[i].size(), words[i+1].size());
            bool ordered = true;

            string w1 = words[i], w2 = words[i+1];
            for(int j =0;j< curSize; j++){
            char& c1 =w1[j];
            char& c2 = w2[j];

if(c1 == c2){
    continue;
}

if(lex[c1] > lex[c2]) return false;
else {
    ordered = false;
    break;
};
            }
if(ordered)
if(w1.size() > w2.size())
return false;

        }
        return true;
    }
};