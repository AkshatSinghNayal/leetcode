class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end()); // store all nums1
        unordered_set<int> result;  

        for (int x : nums2) {
            if (s.count(x)) {  // check existence in O(1)
                result.insert(x); // keeps only unique
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
