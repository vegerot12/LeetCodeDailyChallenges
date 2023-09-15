class SummaryRanges {
    private:
    map<int,bool> intr ; // tree Map
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        intr[value] = true;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(auto itr: intr){
          

           if( !res.empty() && res.back()[1] + 1 == itr.first){
                res.back()[1] = itr.first;
            }
            else{
            res.push_back({itr.first, itr.first});

            }
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */