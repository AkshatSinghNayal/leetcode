class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n  = nums.size(); 
        int mini= INT_MAX , minDiff = INT_MAX , ans ; 
        sort( nums.begin() , nums.end()) ; 
        for( int i  = 0  ; i < n ;i++ ){
            int j = i+1 ; 
            int k = n-1 ; 
            if( i > 0 and nums[i] ==  nums[i-1]) continue ; 
            int third = nums[i]; 
            while( j < k){
                int sum = nums[j]+nums[k]+third; 
                
                if( sum < target ){
                    j++;
                    minDiff = abs( sum- target ); 
                    if( mini>= minDiff ){
                        mini = minDiff;
                        ans = sum; 
                    }
                }
                else if( sum > target ){
                   minDiff = abs( sum- target ); 
                    if( mini>= minDiff ){
                        mini = minDiff;
                        ans = sum; 
                    }
                    k--;
                }
                else{
                    return target; 
                    j++;k--;
                    while( j < n and nums[j] == nums[j-1]) j++; 
                    while( k>=0 and nums[k] == nums[k+1]) k--; 
                }
            }
            
        }
        return ans;
    }
};