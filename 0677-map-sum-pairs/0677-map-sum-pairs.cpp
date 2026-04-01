class MapSum {
public:
    unordered_map<string,int>mp;
    unordered_map<string,int>prefixArry;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        auto leftValueAddOrSub = val - mp[key];
        mp[key] = val;
        string temp = "";
        for(auto& it : key ){
            temp+=it;
            prefixArry[temp]+=leftValueAddOrSub;
        }
    }
    
    int sum(string prefix) {
        return prefixArry[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */