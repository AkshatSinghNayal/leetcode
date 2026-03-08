////// I bow to Lord Satyanarayan and Lord Hanuman ///////////
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> prefix(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        
        int ans = INT_MAX;
        
        for(int i = 0; i < n; i++){
            long long needed = target + prefix[i];
            
            int j = lower_bound(prefix.begin() + i + 1, prefix.end(), needed) - prefix.begin();
            
            if(j <= n){
                ans = min(ans, j - i);
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};