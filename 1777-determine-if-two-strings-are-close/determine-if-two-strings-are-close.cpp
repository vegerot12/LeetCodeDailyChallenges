/*

"cabbba"
word2 =
"abbccc"
Output
false
Expected
true

1. we find freq of each, sort the freq and if the there are ele with same num of freq in both and all the ele pres in one must be there in another too

2. so w1,w2 check if same freq are there so that all 3 bbb can be ccc and onre c can be one a and 2 a can become 2 b


*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>w1(26,0),w2(26,0),w3(26,0),w4(26,0);
        for(char c:word1)
            w1[c-'a']++,w3[c-'a'] = 1;
    
        for(char c:word2)
            w2[c-'a']++,w4[c-'a'] = 1;
        
        sort(begin(w1),end(w1));
        sort(begin(w2),end(w2));
        return w1==w2&&w3==w4;
    }
};