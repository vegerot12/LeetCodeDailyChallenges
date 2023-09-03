class Solution {
public:
// O(1) space for map 26 chars
// TC:  ~ O(n)  we iterate all the words twice. once with prev word and once with next word 
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

            if(c1 == c2){ // as long as both words are equal we need to keep checking so continue 
            continue;
            }

            if(lex[c1] > lex[c2]) return false; // if we found first word is larger lex then return false and end the program
            else { // if first word is small this string is accepted we break and move to check next strings 
                ordered = false; // we  reset this flag here to handle an edge case where all compared chars are equal but second word is smaller than first word
                break; 
            }
            }
            if(ordered){ // all compared chars are equal but second word is smaller than first word
            if(w1.size() > w2.size())
            return false;
            }

       }
        return true;
    }
};


/// METHOD 2 :
/*
class Solution {
public:
// we need to chck if the words in the dict are arranged properly or nto
// so we check by 2 words 
// and see each char in the two words 
// if both char are same we simply continue
// if both are diff chars , if first word char is before the second word char then return true else return false
// likewise we check the first non equal char and return  
    bool ordered(string s, string t,map<char,int> alp){
        for(int i=0;i<s.size()&& i<t.size();i++){
            if(s[i]!=t[i]){
                return alp[s[i]] < alp[t[i]];
            }
        }
        return s.size() <= t.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> alp;
        for(int i=0;i<order.size();i++){
           alp[order[i]]=i;
        }
        
        for(int i=0;i<words.size()-1;i++){
            // check for each pair of words
            // even if one word is not matching return false
          if(!ordered(words[i],words[i+1], alp))
              return false;
        }
        return true;
    }
};
*/