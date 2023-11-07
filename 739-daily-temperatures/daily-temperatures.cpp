class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {


        int n = t.size();
        vector<int> res(n,0);
        int hottest = t[n-1];
        

        for(int i = n-2; i>=0;i--){

            if(t[i] >= hottest) {
                hottest = t[i];
                continue;
            }


            
            
                int days = 1;
                while( t[i] >= t[i+days]){
                    
                    days += res[i+days];
                }
              
                 res[i] = days;
            
        }


        return res;
    }
};