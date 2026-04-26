class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size() ; 
        if( n<3 ) return-1 ; 
        int mini = INT_MAX ; 
        unordered_map<int,vector<int>>mp; 
        for(int i = 0 ; i< n; i++ ){
            mp[nums[i]].push_back(i); 
        }

        for(auto& it : mp ){
            auto [ele , vec] = it; 
            for (int i = 0; i + 2 < vec.size(); i++) {
    int a = vec[i];
    int b = vec[i + 1];
    int c = vec[i + 2];

    int sum = abs(a - b) + abs(b - c) + abs(c - a);
    mini = min(mini, sum);
}

        }
        
        return (mini== INT_MAX) ? -1 : mini;
    }
};