class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        int hottest = t[n-1];
        vector<int> res(n, 0);

        for(int i =n-2 ; i>= 0 ;i--){
            if(t[i] >= hottest) {
                hottest = t[i];
                continue;
            }

            int days = 1;

            while(i+days < n and t[i] >= t[i+days]){
                days= days+ res[days+i];

            }

            res[i] = days;

        }
        return res;
    }
};