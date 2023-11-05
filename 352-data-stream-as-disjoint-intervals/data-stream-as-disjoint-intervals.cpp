class SummaryRanges {
public:
    vector<vector<int>> res;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        vector<int> newInt = {value, value};
        int overlap = 0,i=0;

        for(i = 0;i< res.size();i++){

            if(newInt[1]+1 < res[i][0]) break; 

            if(newInt[0]-1 <= res[i][1]){
                overlap++;
                newInt[0] = min(newInt[0], res[i][0]);
                newInt[1] = max(newInt[1], res[i][1]);
            }
        }

        if(overlap){
            res.erase(res.begin()+(i-overlap) , res.begin()+i);

        }
        res.insert(res.begin()+(i-overlap), newInt);

        
    }
    
    vector<vector<int>> getIntervals() {
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */