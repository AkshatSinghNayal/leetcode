class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans; 
        sort(nums.begin() , nums.end()) ; 
        int n = nums.size() ; 

        for(int i  = 0  ; i< n ; i++ ){
            if( i>0 and nums[i] == nums[i-1]) continue;
            for(int j =  i+1 ; j<n ;j++){
                if( j-i+1 > 2 and nums[j] == nums[j-1]) continue;
                int first = nums[i];
                int second = nums[j];
                int left = j+1;
                int right = n-1;

                while( left < right ){
                    long long sum = (long long)first + second + nums[left] + nums[right];
                    

                    if( sum<  target ){
                        left++;
                    }
                    else if( sum > target ){
                        right--; 
                    }
                    else{
                        ans.push_back({ first , second , nums[left] , nums[right]}); 
                        left++; 
                        right--; 

                        while( left < right and nums[left] == nums[left-1] ) left++;
                        while( right > left and nums[right] == nums[right+1]) right--;
                    }
                }
                
            }
        }
        return ans; 
    }
};