class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        unordered_map<int,int>mp; 
        int n = nums.size(); 
        if( n== 1 ) return 1; 
        int maxi = INT_MIN , mini = INT_MAX; 
        for(int i  = 0 ;i<n ;i++ ){
            maxi  = max(maxi , nums[i]); 
            mini = min(mini , nums[i]); 
            mp[nums[i]] =i; 
        }

        int removal = nums.size()+1; 
        int smaller = INT_MAX , greater = INT_MIN;
        
        greater = max(mp[mini] , mp[maxi]); 
        smaller = min(mp[mini], mp[maxi]); 
        

        removal = min({removal , greater + 1 , n-smaller, (n-greater)+(smaller+1 )}); 
        return removal;
        
    }
};