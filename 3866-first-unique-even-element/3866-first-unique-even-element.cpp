class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> mp; 
        for(auto&it : nums ){
            mp[it]++; 
        }
        for(auto& it : nums ){
            if( it%2 == 0 and mp[it] == 1 ) return it;
        }
        return -1; 
    }
};