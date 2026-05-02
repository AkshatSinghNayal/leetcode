class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        long long prev = LLONG_MIN; 
        for(auto& it: nums ){
            if( prev != it ){
                prev = it;
            }
            else{
                return true;
            }
        }
        return false;
    }
};