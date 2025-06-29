
class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency of each character
        map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }

        // Step 2: Create a vector of pairs to sort by frequency
        vector<pair<int, char>> freq;
        for (auto& it : mp) {
            freq.push_back({it.second, it.first});
        }

        // Step 3: Sort the vector by frequency in descending order
        sort(freq.rbegin(), freq.rend());

        // Step 4: Build the result string
        string result;
        for (auto& it : freq) {
            result.append(it.first, it.second);
        }

        return result;
    }
};