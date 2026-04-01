class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        unordered_map<string, vector<int>> mp;
        vector<string> ans(nums.size());
        
        int idx = 0; 
        for (auto& it : nums) {
            string temp = to_string(it);
            
            for (int i = 0; i < temp.size(); i++) {
                temp[i] = mapping[temp[i] - '0'] + '0';    
            }
            
            ans[idx++] = temp;
            mp[temp].push_back(it);
        }

        stable_sort(ans.begin(), ans.end(), [](string a, string b) {
                return stoi(a) < stoi(b);
            });

        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            auto &vec = mp[ans[i]];
            result.push_back(vec.front());
            vec.erase(vec.begin()); 
        }

        return result;
    }
};