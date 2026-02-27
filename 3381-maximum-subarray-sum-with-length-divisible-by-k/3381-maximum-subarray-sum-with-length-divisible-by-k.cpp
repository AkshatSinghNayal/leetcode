class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefix = 0;
        long long ans = LLONG_MIN;

        unordered_map<int, long long> mp;
        mp[0] = 0;   // base case: prefix before array starts

        for(int i = 0; i < n; i++) {
            prefix += nums[i];

            int rem = (i + 1) % k;  // length remainder

            if(mp.count(rem)) {
                ans = max(ans, prefix - mp[rem]);
                mp[rem] = min(mp[rem], prefix);
            } else {
                mp[rem] = prefix;
            }
        }

        return ans;
    }
};


// 🔥 Key Idea

// If subarray length is divisible by k, then:

// (j−i)%k==0

// Which means:

// j%k==i%k

// So instead of using prefix % k,
// we use index % k.

// We store the minimum prefix sum seen for each index % k.


// 🧠 Why This Works

// If two prefix indices have same (index % k),
// their difference is divisible by k.

// So:

// subarray sum = prefix[j] - prefix[i]

// and

// (j - i) % k == 0
// ✅ Now test your failing case:
// [-1,-2,-3,-4,-5], k = 4

// Correct output: -10 ✔

// Now you're about 85–90% there conceptually.
// The only confusion earlier was mixing:

// sum % k

// length % k

// That’s a very common mistake.