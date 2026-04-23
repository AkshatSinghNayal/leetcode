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
            auto &it = p.second;   
            int k = it.size();

            if(k == 1) continue;
            // vector<long long> prefix(k); 
            // prefix[0] = it[0]; 
            // for(int i =1 ; i<k ; i++ ){
            //     prefix[i] = prefix[i-1]+it[i];
            // }
            long long prefix = 0 , suffix = accumulate( it.begin() , it.end() , 0LL); 
            for(int i = 0 ;i < k ;i++ ){
                long long left = ( i> 0 ) ? ( 1LL*it[i]*i - prefix ) : 0; 
                prefix+=it[i];
                long long right= ( i <k-1) ? ( (suffix - prefix)-1LL*it[i]*(k-i-1)) : 0; 
                ans[it[i]] = left+right;
            }
        }

        return ans; 
    }
};