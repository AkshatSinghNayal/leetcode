class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(); 
        int min = *min_element(nums.begin() , nums.end());
        int total = 0; 
        for(auto& it : nums ){
            total+=(it-min);
        }
        return total;
    }
};