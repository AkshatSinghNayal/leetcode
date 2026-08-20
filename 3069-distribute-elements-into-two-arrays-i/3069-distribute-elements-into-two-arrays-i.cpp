class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size(); 
        vector<int>arr1 , arr2; 
        arr1.push_back(nums[0]); 
        arr2.push_back(nums[1]);

        for(int i  = 2; i<n ; i++ ){
            if(arr1.back() > arr2.back() ){
                arr1.push_back(nums[i]); 
            }
            else{
                arr2.push_back(nums[i]); 
            }
        }   
        int i = 0 ; int m = arr1.size() , k = arr2.size(); 
        int j = 0 , x = 0 ; 
        while( i< n and j<m ){
            nums[i++]= arr1[j++]; 
        }   
        while(i< n and x < k ){
            nums[i++]= arr2[x++]; 

        }
        return nums; 
    }
};