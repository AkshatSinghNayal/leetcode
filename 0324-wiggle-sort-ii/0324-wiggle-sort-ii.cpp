class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n  = nums.size(); 
        vector<int>temp = nums; 
        sort(temp.begin() , temp.end()); 
        int greaterHalf = n-1; 
        int smallerHalf = (n-1)/2; 

        for(int i  = 0;i<n ;i++ ){
            nums[i] = ( i&1 ) ? temp[greaterHalf--] : temp[smallerHalf--]; 
        }
    }
};