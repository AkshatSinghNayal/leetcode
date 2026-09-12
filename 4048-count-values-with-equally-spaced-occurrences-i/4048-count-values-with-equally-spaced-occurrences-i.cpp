class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int i  = 0;
        for(auto& it : nums ){
            mp[it].push_back(i) ; 
            i++;
        }
        unordered_set<int>st;
        
        for(auto& it : nums){
            vector<int> vec = mp[it]; 
            if( !st.count(it) and vec.size() ==  3 and abs(vec[0]-vec[1]) == abs(vec[1] - vec[2])  ){
                st.insert(it);
            }
        }
        return st.size();
    }
};