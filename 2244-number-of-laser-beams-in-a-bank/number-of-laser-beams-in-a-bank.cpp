class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int pre=0, cur=0, res=0;

        for(int i =0;i<bank.size();i++){
            
            for(int j = 0;j<bank[0].size();j++){
                if(bank[i][j]=='1') cur++;

            }
            if(cur == 0) continue;
            res+= cur*pre;
            pre = cur;
            cur=0;
        }

        return res;
        
    }
};