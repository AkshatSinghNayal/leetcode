class Solution {
public:
    int characterReplacement(string nums, int k) {
        unordered_map<int,int>mp ; 
        int left= 0 , right =0 , n =nums.size();
        int maxi = INT_MIN, maxFreq = 1;
        while(right<n){
            mp[nums[right]]++;
            maxFreq = max(maxFreq , mp[nums[right]]);
            while( left<right and (right-left+1)>maxFreq+k  ){
                mp[nums[left]]--;   
                left++; 
            }

            maxi = max(maxi , right-left+1);

            right++; 
        }
        return maxi ;
    }
};