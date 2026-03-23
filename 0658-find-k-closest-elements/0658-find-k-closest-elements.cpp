class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto right  = lower_bound(arr.begin() , arr.end() , x ) - arr.begin(); 
        int left = right-1 , n = arr.size();
        while(k--){
            if( right < n and left >=0 and  abs( x - arr[right]) < abs(x - arr[left]) ){
                right++; 
            }
            else if( left < 0 ){
                right++;
            }
            else if(right>=n){
                left--; 
            }
            else{
                left--; 
            }
        }
        return vector<int>( arr.begin() + left + 1 , arr.begin() + right );
    }
};