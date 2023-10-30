class TimeMap {
public:
        unordered_map<string, map<int, string>> m; // {key , {time1, val1},{time2, val2}}
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        if(m.find(key) != m.end()){
            auto& tmap =  m[key];
            auto resItr = tmap.upper_bound( timestamp);
            if(resItr != tmap.begin()) return prev(resItr)->second;
        }

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */