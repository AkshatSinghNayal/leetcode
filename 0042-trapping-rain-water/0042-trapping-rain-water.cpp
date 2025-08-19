class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0 ; 
        int right = height.size()-1 ; 
        int waterStored = 0 ; 
        int leftMax = -1 , rightMax = -1 ;
        while( left < right){
             leftMax = max(leftMax,height[left]); 
             rightMax = max(rightMax , height[right]);

             if( leftMax < rightMax){
                waterStored+= leftMax - height[left];
                left++;
             }
             else{
                waterStored+= rightMax - height[right];
                right--;
             }

        }
        return waterStored;
    }
};