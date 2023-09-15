class SummaryRanges {
    private:
    set<int> values;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        values.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(values.empty()) return {};
        vector<vector<int>> res;

        int left =-1, right=-1;
        for(auto& value:values){
            if(left == -1 ){
                left = right = value;
            }
            else if(right+1 == value){
                right = value;
            }
            else{
                res.push_back({ left, right});
             left = right = value;  // because cur value did not fit in the cur interval so we closed it and put in res we need to begin a new interval from cur value so assign both left and right with valye 

            }
            
        }
        res.push_back({ left, right});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */