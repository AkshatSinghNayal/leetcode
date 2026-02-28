class Solution {
public:
    int captureForts(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0  , count = 0; 
        int index = 0 ; 
        int backIdx = n-1;
        while( index < n and  nums[index] != 1 ) index++; 
        while(backIdx >= 0  and  nums[backIdx] !=1 ) backIdx--; 
        index++; backIdx--; 

        while( index < n ){
            if( nums[index] == 0  ){
                count++; 
            }
            else if( nums[index] == -1 ){
                maxi = max( count , maxi ); 
                while( index < n and nums[index] != 1 ) index++;
                count = 0 ;
            }
            else{
                count= 0 ; 
            }
            index++;
        }
        count = 0 ; 
        while( backIdx >= 0 ){
            if( nums[backIdx] == 0  ){
                count++; 
            }
            else if( nums[backIdx] == -1 ){
                maxi = max( count , maxi ); 
                while( backIdx >= 0  and nums[backIdx] != 1 ) backIdx--;
                count = 0 ;
            }
            else{
                count= 0 ; 
            }
            backIdx--;
        }

        return maxi ; 
    }
};