class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m, cnts;


        for( auto n:arr){
            m[n]++;
            cnts[m[n]-1]--;
            cnts[m[n]]++;

        }

        for( auto c:cnts){
            if(c.second >1) return false;
        }
        return true;
    }
};