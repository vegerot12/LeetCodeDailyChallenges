class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int grp) {
        if(hand.size() % grp != 0) return false;
        map <int, int> m;

        for(int i:hand){
            m[i]++;
        }

        while(!m.empty()){
            int start = m.begin()->first;
           
            for(int i =0;i<grp;i++){
                if(m[start+i]==0) return false;
                else if(--m[start+i]<1) m.erase(start+i);

            }

        }
        return true;

        
    }
};
