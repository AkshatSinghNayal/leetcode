class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if( nums.size() ==1 ) return false ; 
        return (nums.size() != set(nums.begin(),nums.end()).size());
    }
};