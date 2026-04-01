class MapSum {
public:
    unordered_map<string,int> mp; 

    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int cost = 0; 
        for(auto& it : mp ){
            auto temp = it.first.substr(0, prefix.size());
            if( temp == prefix ){
                cost+=it.second;
            }
        }
        return cost;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */