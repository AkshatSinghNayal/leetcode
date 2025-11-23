class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp ; 
        for( auto &it : s ) mp[it ]++ ; 
        int masking = INT_MAX^1 ; 
        long long evenlen = 0 , oddlen = 0 ;
        for( auto &it : mp ){
            evenlen += (it.second & masking) ; 
            oddlen = oddlen | (it.second&1) ;
        }
        return evenlen + oddlen ; 
    }
};


// for(auto x:mp){
//     length += (x.second & mask);  // Add even part of count
//     middle |= x.second & 1;        // Check if any count is odd
// }


// Let's trace with `s = "aaabbbccdd"`:

// | Char | Count | Binary | `count & mask` (even part) | `count & 1` (is odd?) |
// |------|-------|--------|----------------------------|----------------------|
// | a    | 3     | 011    | 010 = 2                   | 1 (yes)              |
// | b    | 3     | 011    | 010 = 2                   | 1 (yes)              |
// | c    | 2     | 010    | 010 = 2                   | 0 (no)               |
// | d    | 2     | 010    | 010 = 2                   | 0 (no)               |

// **After loop:**
// - `length = 2 + 2 + 2 + 2 = 8` (all the even parts)
// - `middle = 1 | 1 | 0 | 0 = 1` (at least one odd exists)

// **Return:** `8 + 1 = 9` ✓

// ## Bit operations explained:

// ### 1. `x.second & mask` → Gets even part
// ```
//   3 = 011
// &     110 (mask)
//   -------
//       010 = 2
// ```
// Same as `x.second - 1` for odd numbers!

// ### 2. `x.second & 1` → Checks if odd
// ```
//   3 = 011
// &     001
//   -------
//       001 = 1 (odd)

//   2 = 010
// &     001
//   -------
//       000 = 0 (even)
// ```

// ### 3. `middle |= ...` → Sets middle to 1 if ANY odd exists
// ```
// middle = 0
// middle |= 1  → middle = 1
// middle |= 1  → middle = 1 (stays 1)
// middle |= 0  → middle = 1 (stays 1)

