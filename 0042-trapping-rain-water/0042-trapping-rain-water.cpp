class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size() , 0 ); 
        vector<int> suffix(height.size() , 0 ) ;
        int size = height.size()-1;
        prefix[0] = height[0];
        suffix[size] = height[size];
        int waterStored = 0 ;
        int leftMax = -1;

        // for( int i = 1 ; i<size+1 ; i++){
        //     prefix[i] = max(prefix[i-1] ,height[i]);
        // }
        for( int j = size-1 ; j>= 0 ; j--){
            suffix[j] = max( suffix[j+1], height[j]);
        }

        for( int i = 0 ; i<height.size() ; i++){
            leftMax = max(leftMax,height[i]);
            int rightMax = suffix[i];
            waterStored+=min(leftMax , rightMax) - height[i];
        }

        return waterStored;
    }
};