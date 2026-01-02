class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp ; 
        for( auto & it : nums){
            mp[it]++; 
            if( mp[it] == 2 ) return it; 
        }
        return -1;
    }
};