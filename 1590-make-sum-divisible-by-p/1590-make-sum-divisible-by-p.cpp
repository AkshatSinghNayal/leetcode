class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int> mp ; 
        mp[0] = -1;
        int prefix = 0 ; 
        int n  = nums.size() ; 
        int target = 0  ; 
        for( auto& x : nums){
            target = (target+x)%p ;
        }

        if( target == 0  ) return 0 ;
        int ansLen =  n ; 

        for( int i = 0 ; i< n; i++){
            prefix = (prefix+nums[i])%p; 
            int compliment =( prefix - target + p )%p ; 
            if( mp.count(compliment)){
                ansLen = min( ansLen , i - mp[compliment]) ;
            }
            mp[prefix] = i ;
        }
        return ansLen == n ? -1 : ansLen; 
    }
};

/*

mp[prefix] = i;  // This OVERWRITES any previous occurrence
```

## Visual Explanation

Let's say we have a situation where the **same prefix value** appears at multiple indices:
```
Array:    [a, b, c, d, e, f, g]
Index:     0  1  2  3  4  5  6
Prefix%p:  3  5  7  5  2  7  4
                ↑     ↑     ↑
              same    same  same (value 7 appears at indices 2, 5)
```

When we're at index 6 and need to find prefix value 7:
- If we use index 2: subarray length = 6 - 2 = **4** (removing [d,e,f,g])
- If we use index 5: subarray length = 6 - 5 = **1** (removing [g])




dry run ->>



Perfect! Let me trace through nums = [3, 1, 4, 2], p = 6 step by step in complete detail.
Step 0: Calculate Target
cpptarget = 0;
for(auto& x : nums){
    target = (target + x) % p;
}
```
```
target = (0 + 3) % 6 = 3
target = (3 + 1) % 6 = 4
target = (4 + 4) % 6 = 2
target = (2 + 2) % 6 = 4
target = 4 ← This is the "excess" remainder we need to remove
Total sum = 10, and 10 % 6 = 4. We need to remove a subarray whose sum % 6 = 4.

Step 1: Initialize
cppmp[0] = -1;  // Base case
prefix = 0;
ansLen = n = 4;
Map state: {0: -1}
This means "a prefix sum of 0 exists before the array starts"

Step 2: Process Each Element
i = 0, nums[0] = 3
cppprefix = (0 + 3) % 6 = 3
compliment = (3 - 4 + 6) % 6 = 5
What we're asking:

Current prefix sum % 6 = 3
We need: "Is there a previous index where prefix % 6 = 5?"
Because: If prefix[j] = 5, then (prefix[0] - prefix[j]) % 6 = (3 - 5 + 6) % 6 = 4 ✓

Check map: mp.count(5) → No, 5 is not in the map
Update map: mp[3] = 0
Map state: {0: -1, 3: 0}

i = 1, nums[1] = 1
cppprefix = (3 + 1) % 6 = 4
compliment = (4 - 4 + 6) % 6 = 0
What we're asking:

Current prefix sum % 6 = 4
We need: "Is there a previous index where prefix % 6 = 0?"
Because: If prefix[j] = 0, then (prefix[1] - prefix[j]) % 6 = (4 - 0) % 6 = 4 ✓

Check map: mp.count(0) → Yes! 0 is at index -1
Calculate length:
cppansLen = min(4, 1 - (-1)) = min(4, 2) = 2
What this means:

We found a match!
Subarray from index (-1 + 1) = 0 to index 1
That's [3, 1] with sum = 4, and 4 % 6 = 4 ✓
Length = 2

Update map: mp[4] = 1
Map state: {0: -1, 3: 0, 4: 1}
Current ansLen: 2

i = 2, nums[2] = 4
cppprefix = (4 + 4) % 6 = 2
compliment = (2 - 4 + 6) % 6 = 4
What we're asking:

Current prefix sum % 6 = 2
We need: "Is there a previous index where prefix % 6 = 4?"
Because: If prefix[j] = 4, then (prefix[2] - prefix[j]) % 6 = (2 - 4 + 6) % 6 = 4 ✓

Check map: mp.count(4) → Yes! 4 is at index 1
Calculate length:
cppansLen = min(2, 2 - 1) = min(2, 1) = 1
What this means:

We found a better match!
Subarray from index (1 + 1) = 2 to index 2
That's just [4] with sum = 4, and 4 % 6 = 4 ✓
Length = 1 ← This is better!

Update map: mp[2] = 2
Map state: {0: -1, 3: 0, 4: 1, 2: 2}
Current ansLen: 1

i = 3, nums[3] = 2
cppprefix = (2 + 2) % 6 = 4
compliment = (4 - 4 + 6) % 6 = 0
What we're asking:

Current prefix sum % 6 = 4
We need: "Is there a previous index where prefix % 6 = 0?"

Check map: mp.count(0) → Yes! 0 is at index -1
Calculate length:
cppansLen = min(1, 3 - (-1)) = min(1, 4) = 1
What this means:

Subarray from index 0 to index 3
That's [3, 1, 4, 2] (entire array!) with sum = 10, and 10 % 6 = 4 ✓
Length = 4
But we already have ansLen = 1, so no update

Update map: mp[4] = 3 ← Overwrites mp[4] from 1 to 3!
Map state: {0: -1, 3: 0, 4: 3, 2: 2}
Current ansLen: 1 (unchanged)

Final Answer
cppreturn ansLen == n ? -1 : ansLen;
return 1 == 4 ? -1 : 1;
return 1;
```

**Answer: 1**

Remove the subarray `[4]` at index 2. The remaining elements `[3, 1, 2]` have sum = 6, which is divisible by 6! ✓

---

## Visual Summary
```
Array:      [3,    1,    4,    2]
Index:       0     1     2     3
Prefix%6:    3     4     2     4

target = 4 (need to remove subarray with sum%6 = 4)

At i=1: Found match! Subarray [3,1] (length 2)
At i=2: Found match! Subarray [4]   (length 1) ← BEST!
At i=3: Found match! Subarray [3,1,4,2] (length 4) - ignored

Why "Last Index Storing" Helped Here
At index 3, we overwrote mp[4] from 1 to 3:

If someone later needed prefix value 4, they'd get index 3 (not 1)
This ensures the shortest subarray ending at that future position

In this problem, it didn't affect the answer because we already found the optimal solution at i=2, but it demonstrates the principle: always store the most recent occurrence to guarantee shortest subarrays!

*/