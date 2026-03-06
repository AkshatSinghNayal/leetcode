class Solution {
public:

   struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t h = 0;
        for (auto x : v)
            h ^= hash<int>()(x);
        return h;
    }
};
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<vector<int> , int , VectorHash> mp;

        sort( nums.begin() , nums.end()); 
        mp[nums]++; 
        while( next_permutation(nums.begin() , nums.end())){
            mp[nums]++; 
        }
        vector<vector<int>>ans;

        for(auto& it : mp ){
            auto [ vec , freq ] = it ; 
            for( int i = 0  ; i< freq ; i++ ){
                ans.push_back( vec ); 
            }
        }
        return ans;
    }
};