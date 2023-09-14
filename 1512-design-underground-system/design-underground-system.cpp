class UndergroundSystem {
public:
    unordered_map<int, pair<string,int>> boarded;
    unordered_map<string , pair<int,int>> tripAvg;

    UndergroundSystem() {}

   
    void checkIn(int id, string stationName, int t) {
        boarded[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& p = boarded[id];
        int startTime = p.second;
        string startStation = p.first;
        string route = startStation+"_"+stationName;;
       auto cur = tripAvg.find(route);
       if(cur!= tripAvg.end()){
      
       
         tripAvg[route] = {tripAvg[route].first + (t-startTime) , tripAvg[route].second+1};
       }
       else {
            tripAvg[route] = {t-startTime, 1};
       }
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto& p =  tripAvg[startStation+"_"+endStation];
        return (double)(p.first)/ (double)(p.second);

    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */