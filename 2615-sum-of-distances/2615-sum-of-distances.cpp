class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size(); 
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> mp; 

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        // instead of looping i → j, process each group once
        for(auto &p : mp){
            auto &it = p.second;   // same vector you were using
            int k = it.size();

            if(k == 1) continue;

            // prefix sum of indices
            vector<long long> pref(k);
            pref[0] = it[0];

            for(int i = 1; i < k; i++){
                pref[i] = pref[i - 1] + it[i];
            }

            // compute answer for each index in this group
            for(int i = 0; i < k; i++){
                long long left = (long long)it[i] * i - (i > 0 ? pref[i - 1] : 0);
                long long right = (pref[k - 1] - pref[i]) - (long long)it[i] * (k - i - 1);
                ans[it[i]] = left + right;
            }
        }

        return ans; 
    }
};