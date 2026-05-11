class Solution {
public:
    bool isChar(char c) { return (c >= 'a' and c <= 'z'); }

    vector<int> countWordOccurrences(vector<string>& chunks,
                                     vector<string>& queries) {
        int n = queries.size();
        unordered_map<string, int> mp;
        vector<int> ans(n);
        string temp = "";
        for (auto& it : chunks) {
            temp += it;
        }
        string current = "";
        int i  = (temp[0] == '-') ? i= 1 : 0; 
        int size = temp.size(); 
        size = (temp[size-1] == '-') ? size-1 : size; 
        for ( i ; i < size; i++) {
            char it = temp[i];

            if (isChar(it)) {
                current += it;
            } else if (it == ' ' or((i-1>=0 and i+1 <size) and ( it=='-' and !isChar(temp[i-1])) or ( it=='-' and !isChar(temp[i+1])))) {
                if(!current.empty())  mp[current]++;
                cout<< current << " "; 
                current.clear();
            } else {
                current += it;
            }
        }
        if(!current.empty()) mp[current]++;
        for (int i = 0; i < n; i++) {
            ans[i] = mp[queries[i]];
        }
        return ans;
    }
};