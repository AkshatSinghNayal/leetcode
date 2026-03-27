class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(); 
        
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i]; 
        }

        int mini = INT_MAX;

        for(int i = 0; i < n; i++){
            long long need = target + (i > 0 ? prefix[i-1] : 0);

            auto it = lower_bound(prefix.begin(), prefix.end(), need);

            if(it != prefix.end()){
                int idx = it - prefix.begin();
                mini = min(mini, idx - i + 1);
            }
        }

        return mini == INT_MAX ? 0 : mini;
    }   
};