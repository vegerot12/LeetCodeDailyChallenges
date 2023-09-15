class SummaryRanges {
    vector<vector<int>> res;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        vector<int> newInterval = {value, value};
        int i =0,overlap=0;
        int n = res.size();
        // for lopp exit will be when we crossed overlapping section 
        for(i=0;i<n;i++){
            // new interval ending is smaller than cur interval starting , we passed overlapping or consective  section
            if(newInterval[1] +1< res[i][0]) break;
            // if new interval started before cur interval ending 
            if( newInterval[0]-1 <= res[i][1]){
                overlap++;
                newInterval[0] = min(newInterval[0] , res[i][0]);
                newInterval[1] = max(newInterval[1] , res[i][1]);


            }

        }
        if(overlap>0){
            res.erase(res.begin()+(i-overlap) , res.begin()+i );

        }
        res.insert(res.begin()+i-overlap , newInterval);
        
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
 