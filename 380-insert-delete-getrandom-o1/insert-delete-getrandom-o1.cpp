class RandomizedSet {
public:
vector<int> v;
      unordered_map<int,int> m;
  
    bool insert(int val) {
        if(m.find(val)!= m.end()) return false;

        v.emplace_back(val);
        m[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;

        int index = m[val];
        m[v[v.size()-1]] = index;
        swap(v[index], v[v.size()-1]);
        m.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */