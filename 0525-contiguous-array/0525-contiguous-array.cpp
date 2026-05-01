class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefix = 0 ,  n = nums.size() , maxi = 0; 
        unordered_map<int,int>mp ; 
        mp[0] = -1; 
        for(int i  = 0 ; i<n ;i++ ){
            int ele = ( nums[i] == 0 ) ? -1 :1 ;
            prefix+=ele;
            if( !mp.count(prefix)){
                mp[prefix] = i; 
            }
            else{
                maxi = max(maxi , i-mp[prefix]);
            }
        }
        return maxi; 
    }
};