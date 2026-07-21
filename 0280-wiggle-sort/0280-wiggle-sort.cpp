class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size() ,i =1 , j = 2; 
        sort(nums.begin(),nums.end()); 

        while( i<n and j<n ){
            swap(nums[i],nums[j]); 
            i = j+1; 
            j=i+1; 
        }
    }
};