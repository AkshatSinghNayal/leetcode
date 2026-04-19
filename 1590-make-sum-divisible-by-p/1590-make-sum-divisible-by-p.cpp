class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
    long long total = accumulate(nums.begin(), nums.end(), 0LL); 
    int target = total % p;
    if (target == 0) return 0; 

    unordered_map<int,int> freq;
    freq[0] = -1; 

    int ans = nums.size();
    int currentMOD = 0; 

    for (int i = 0; i < nums.size(); i++) {
        currentMOD = (currentMOD + nums[i]) % p; 

        int weWant = (currentMOD - target + p) % p;

        if (freq.count(weWant)) {
            ans = min(ans, i - freq[weWant]);    
        }

        freq[currentMOD] = i;
    }   

    return ans == nums.size() ? -1 : ans;
}
    
};