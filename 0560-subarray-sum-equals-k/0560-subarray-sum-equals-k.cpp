class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map<int,int> mp (n);
        mp[0] = 1 ; 
        int count = 0 ; 
        int sum = 0 ; 
        for(int i =  0 ;i < n ; i++){
            sum+=nums[i] ; 
            int compliment = sum-k; 
            if( mp.count(compliment)){
                count+=mp[compliment]; 
               
            }
          
             mp[sum]++; 
           
        }
        
        return count ; 
    }
};