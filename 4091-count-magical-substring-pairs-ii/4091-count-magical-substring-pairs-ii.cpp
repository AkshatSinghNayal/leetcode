/*
 * Problem : Count Magical Pairs of Substrings
 * Approach: Fix the cut + sliding window (at-most) + subtraction (exactly)
 *
 * ---------------------------------------------------------------------
 * PROBLEM (short)
 * ---------------------------------------------------------------------
 * For every triplet (i, j, k) with 0 <= i <= j < k < n:
 *      s1 = s[i..j]      s2 = s[j+1..k]
 * Count triplets where distinct(s1) == distinct(s2).
 *
 * ---------------------------------------------------------------------
 * IDEA
 * ---------------------------------------------------------------------
 * 1. Brute force over (i, j, k) is O(n^3) -> too slow for n = 1e5.
 *
 * 2. Fix the CUT first. Let the cut be "s1 | s2", where s2 starts at
 *    index `cut` (so s1 ends at index cut-1).
 *      - The choice of i (start of s1) only affects the left side.
 *      - The choice of k (end of s2) only affects the right side.
 *    They are independent, so we can MULTIPLY (like shirts x pants):
 *
 *      ways(cut) = SUM over c = 1..26 of
 *                  (#starts i with exactly c distinct in s[i..cut-1])
 *                * (#ends   k with exactly c distinct in s[cut..k])
 *
 * 3. "Exactly c" is hard to count directly, but "at most c" is easy
 *    with a sliding window (distinct count never decreases when a
 *    substring grows). Then:
 *
 *      exact(c) = atMost(c) - atMost(c - 1)
 *
 * 4. Distinct letters can only be 1..26, so we run 26 sliding-window
 *    passes per side -> O(26 * n) total.
 *
 * ---------------------------------------------------------------------
 * COMPLEXITY
 * ---------------------------------------------------------------------
 * Time  : O(26 * n)
 * Space : O(27 * n) for the two tables (about 21 MB for n = 1e5)
 *
 * Note  : the answer can reach ~1e14, so we use long long.
 */

#include <array>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();
        long long count = 0;

        // atMost1[r][ch] = number of starts i such that s[i..r] has
        //                  AT MOST `ch` distinct characters.
        //                  (substrings ENDING at r)
        //
        // atMost2[l][ch] = number of ends k such that s[l..k] has
        //                  AT MOST `ch` distinct characters.
        //                  (substrings STARTING at l)
        //
        // Index ch = 0 is never filled, so it stays 0. That is exactly
        // right: no non-empty substring has <= 0 distinct characters.
        // This lets us write exact(1) = atMost(1) - atMost(0) safely.
        vector<array<int, 27>> atMost1(n, array<int, 27>{});
        vector<array<int, 27>> atMost2(n, array<int, 27>{});

        // -------------------------------------------------------------
        // STEP 1: LEFT SIDE (substrings ending at j)
        // -------------------------------------------------------------
        // For each limit `ch`, slide a window [i..j] left to right.
        // The window is the LONGEST substring ending at j with
        // <= ch distinct characters. Every shorter substring ending at
        // j (starting further right) is also valid, so the count of
        // valid starts is the window length.
        for (int ch = 1; ch <= 26; ch++) {
            int freq[26] = {};   // frequency of each letter in window
            int distinct = 0;    // distinct letters in window
            int i = 0;           // left edge of the window

            for (int j = 0; j < n; j++) {
                // Add s[j] to the window. If it is new, distinct++.
                if (freq[s[j] - 'a']++ == 0) distinct++;

                // Too many distinct letters? Shrink from the left.
                // i only moves right, so total work is O(n) per `ch`.
                while (distinct > ch) {
                    // Remove s[i]. If its count hits 0, a letter vanished.
                    if (--freq[s[i] - 'a'] == 0) distinct--;
                    i++;
                }

                // All starts in [i..j] give <= ch distinct.
                atMost1[j][ch] = j - i + 1;
            }
        }

        // -------------------------------------------------------------
        // STEP 2: RIGHT SIDE (substrings starting at j)
        // -------------------------------------------------------------
        // Mirror image. Slide a window [j..k] right to left.
        // The window is the LONGEST substring starting at j with
        // <= ch distinct characters, so its length is the number of
        // valid ends k.
        for (int ch = 1; ch <= 26; ch++) {
            int freq[26] = {};
            int distinct = 0;
            int k = n - 1;       // right edge of the window

            for (int j = n - 1; j >= 0; j--) {
                // Add s[j] to the window.
                if (freq[s[j] - 'a']++ == 0) distinct++;

                // Too many distinct letters? Shrink from the right.
                while (distinct > ch) {
                    if (--freq[s[k] - 'a'] == 0) distinct--;
                    k--;
                }

                // All ends in [j..k] give <= ch distinct.
                atMost2[j][ch] = k - j + 1;
            }
        }

        // -------------------------------------------------------------
        // STEP 3: COMBINE
        // -------------------------------------------------------------
        // `cut` = index where s2 starts. Valid range is 1..n-1 because
        // s1 needs at least one character (ends at cut-1 >= 0) and s2
        // needs at least one character (starts at cut <= n-1).
        for (int cut = 1; cut <= n - 1; cut++) {
            for (int ch = 1; ch <= 26; ch++) {
                // Starts i with EXACTLY ch distinct in s[i..cut-1].
                long long left  = atMost1[cut - 1][ch] - atMost1[cut - 1][ch - 1];

                // Ends k with EXACTLY ch distinct in s[cut..k].
                long long right = atMost2[cut][ch] - atMost2[cut][ch - 1];

                // Every valid i pairs with every valid k -> multiply.
                count += left * right;
            }
        }

        return count;
    }
};

/*
 * ---------------------------------------------------------------------
 * QUICK CHECK: s = "aba"  ->  expected 2
 * ---------------------------------------------------------------------
 * cut = 1 : "a | ba"  -> left exact1 = 1 ; right exact1 = 1, exact2 = 1
 *                         1*1 (c=1) + 0*1 (c=2)               = 1
 * cut = 2 : "ab | a"  -> left exact1 = 1, exact2 = 1 ; right exact1 = 1
 *                         1*1 (c=1) + 1*0 (c=2)               = 1
 * Total = 2
 */