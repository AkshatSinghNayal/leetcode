class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size(); 
        long long prefix =0 ; 
        int i  = 0  , last =-1; 
        while( i < n ){
            if( last != -1 and nums[i] <= last){
                prefix-=last;
                while(i<n){
                    prefix-=nums[i]; 
                    i++; 
                }
            }
            if( i<n){
            prefix+= nums[i];
            last = nums[i]; 
            }
            i++; 
        }
        return ( prefix == 0  ) ? -1 : ( prefix >0 ) ? 0 : 1; 
    }
};